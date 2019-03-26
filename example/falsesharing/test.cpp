
#include <iostream>
#include <new>
#include <atomic>
#include <thread>
#include <vector>
#include <string.h>

#ifdef USE_LIKELY
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)
#else
#define likely(x) x
#define unlikely(x) x
#endif

//cat /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size
//c++17:  std::hardware_destructive_interference_size
constexpr size_t cacheline_size = 64;
constexpr size_t op_count = 100000000;

#ifdef USE_ATOMIC
typedef std::atomic<uint64_t> Value;
#elif defined(USE_VOLATILE)
typedef volatile uint64_t Value;
#else
typedef uint64_t Value;
#endif

template<bool = true>
struct FalseSharing
{
	Value value;
};

template<>
struct FalseSharing<false>
{
	alignas(cacheline_size) Value value;
};

char buf[102400];

int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		std::cout << "usage: " << argv[0] << " thread_num  true/false(true: false sharing, false: no false sharing)" << std::endl;
	}
	std::vector<std::thread> threads;
	threads.resize(atoi(argv[1]));
	bool b = (strcmp(argv[2], "true") == 0);

	void * data = buf;
	size_t size = sizeof(buf);
	if(b)
	{
		// aligin cacheline
		if(!std::align(cacheline_size, sizeof(FalseSharing<true>)*1024, data, size))
		{
			std::cout << "align error" << std::endl;
			return -1;
		}
		auto v = reinterpret_cast<FalseSharing<true> *>(data);
		for(size_t i = 0; i < threads.size(); ++i)
		{
			threads[i] = std::thread([i, &v]()
			{			
			    for(size_t j = 0 ; unlikely(j < op_count); ++j)
				{
				    ++ v[i].value;
				}
			});
		}
	}
	else
	{
		// aligin cacheline
		if(!std::align(cacheline_size, sizeof(FalseSharing<false>)*1024, data, size))
		{
			std::cout << "align error" << std::endl;
			return -1;
		}
		auto v = reinterpret_cast<FalseSharing<false> *>(data);
		for(size_t i = 0; i < threads.size(); ++i)
		{
			threads[i] = std::thread([i, &v]()
			{			
			    for(size_t j = 0 ; unlikely(j < op_count); ++j)
				{
				    ++ v[i].value;
				}
			});
		}
	}

	for(size_t i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}

	return 0;
}

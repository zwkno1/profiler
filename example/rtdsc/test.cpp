#include <sys/time.h>
#include <stdint.h>

inline uint64_t rdtsc()
{
        uint32_t hi, lo;
        __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
        return ( (uint64_t)lo)|( ((uint64_t)hi)<<32 );
}

int main(int argc, char * argv[])
{
        if(argc > 1)
        {
                struct timeval tv;
                for(int i = 0;i < 100000000; ++i)
                {
                        gettimeofday(&tv, 0);
                }
        }
        else
        {
                uint64_t v;
                for(int i = 0;i < 100000000; ++i)
                {
                        v = rdtsc();
                }
        }

        return 0;
}


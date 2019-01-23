#include "profiler.h"
#include <iostream>
#include <map>

size_t test_map()
{
	std::map<std::string, int> m;
	for(int i = 0; i < 1000000; ++i)
	{
		m[std::to_string(i)] = i;
	}
	return m.size();
}

int main(int argc, char* argv[]) 
{
	Profiler p;
	p.start("profiler_test.prof");
	std::cout << "insert " << test_map() << " times";
	p.stop();
	return 0;
}


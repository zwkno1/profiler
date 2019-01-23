#pragma once

#include <gperftools/heap-profiler.h>

class HeapProfiler
{
public:
	inline void start(const char * prefix)
	{
		if(!IsHeapProfilerRunning())
		{
			HeapProfilerStart(prefix);
		}
	}

	inline void stop()
	{
		if(IsHeapProfilerRunning())
		{
			HeapProfilerStop();
		}
	}

	inline void dump(const char * reason)
	{
		HeapProfilerDump(reason);
	}

	inline char * get()
	{
		return GetHeapProfile();
	}
};

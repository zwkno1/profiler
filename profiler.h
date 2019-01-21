#pragma once

#include <gperftools/profiler.h>

class Profiler
{
public:
    Profiler()
    : started_(false)
    {
    }

    ~Profiler()
    {
        if(started_)
            stop();
    }

    inline void start(const char * outputFile)
    {
        if(started_)
            return;

        started_ = true;
        ProfilerStart(outputFile);
    }

    inline void stop()
    {
        if(!started_)
            return;

        started_ = false;
        ProfilerStop();
    }

private:
    bool started_;
};


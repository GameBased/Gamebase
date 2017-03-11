#include "TimerBase.h"

namespace gamebase
{
    TimerBase::TimerBase()
        : startTicks(0), stopTicks(0), _isRunning(false)
    {
        
    }

    void TimerBase::Start()
    {
        _isRunning = true;
        startTicks = getTicks();
    }

    void TimerBase::Stop()
    {
        if(!isRunning())
        {
            // Already stopped
            return;
        }
        _isRunning = false;
        stopTicks = getTicks();
    }

    void TimerBase::Reset()
    {
        _isRunning = false;
        startTicks = 0;
        stopTicks = 0;
    }

    unsigned int TimerBase::getElapsedTime()
    {
        if(isRunning())
        {
            return getTicks() - startTicks;
        }
        else
        {
            return stopTicks - startTicks;
        }
    }

    bool TimerBase::isRunning()
    {
        return _isRunning;
    }
}

#pragma once

class  TimerBase
{
    private:
        unsigned int startTicks;
        unsigned int stopTicks;
        bool _isRunning;

    public:
        TimerBase();
        bool isRunning();

        void Start();
        void Stop();
        void Reset();

        virtual void Delay(unsigned int ms) = 0;
        virtual unsigned int getTicks() = 0;
        unsigned int getElapsedTime();
};

#include "Gamebase.h"
#include "utils/TimerBase.h"

Gamebase::Gamebase(std::unique_ptr<TimerBase> timerImplementation)
    : timer(std::move(timerImplementation))
{
    
}

void Gamebase::Run()
{
    Run(24);
}

void Gamebase::Run(unsigned int frames_per_second)
{
	const unsigned int ms = 1000/frames_per_second;
	if(!this->Initialize())
    {
        // Initialization failed
        return;
    }

	this->Load();
	while(true)
	{
		timer->Start();
		this->Update();
		this->Draw();
        timer->Stop();

		// Wait until the time for the given frame is elapsed
		if(timer->getElapsedTime() < ms)
		{
			timer->Delay(ms - timer->getElapsedTime());
		}
	}
    this->Unload();
}

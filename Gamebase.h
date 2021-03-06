/*
    MIT License

    Gamebase
    Copyright (c) 2017 Galdin Raphael

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once

// Include core types
#include "core/IComponent.h"
#include "core/IDrawable.h"
#include "core/IDrawableComponent.h"
#include "core/ILoadable.h"

// Include utilities
#include "utils/TimerBase.h"
#include "utils/IGraphicsDevice.h"

#include <memory>

namespace gamebase {
    class Gamebase : IDrawableComponent, ILoadable
    {
        private:
            bool _shouldQuit;

        protected:
            std::unique_ptr<TimerBase> timer;
            bool shouldQuit();
            std::unique_ptr<IGraphicsDevice> graphicsDevice;

        public:
            Gamebase(std::unique_ptr<TimerBase> timerImplementation);

            virtual bool Initialize() = 0;
            virtual void Uninitialize() = 0;

            virtual void Run();
            void Run(unsigned int fps);

            virtual void Quit();
            void registerGraphicsDevice(std::unique_ptr<IGraphicsDevice> graphicsDevice)
            {
                this->graphicsDevice = std::move(graphicsDevice);
            }
    };
}

#pragma once

namespace gamebase
{
    class ILoadable
    {
        public:
            virtual void Load() = 0;
            virtual void Unload() = 0;
    };
}

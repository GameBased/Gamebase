#pragma once

namespace gamebase
{
    class IGraphicsDevice
    {
        public:
            virtual void Clear() = 0;
            virtual void Draw() = 0;
    };
}

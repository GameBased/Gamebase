#pragma once

class ILoadable
{
    public:
        virtual void Load() = 0;
        virtual void Unload() = 0;
};

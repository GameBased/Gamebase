#pragma once

#include "IComponent.h"
#include "IDrawable.h"

namespace gamebase
{
    class IDrawableComponent : public IComponent, public IDrawable
    {
        
    };
}

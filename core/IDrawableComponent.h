#pragma once

#include "IComponent.h"
#include "IDrawable.h"

class IDrawableComponent : public IComponent, public IDrawable
{
    
};

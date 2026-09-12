#pragma once
#include "Object.h"

class IT_Restore :
    public Object
{
public:
    IT_Restore();
    void Use(LivingEntity& target);
};


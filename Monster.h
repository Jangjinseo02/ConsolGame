#pragma once
#include "LivingEntity.h"

class Monster :
    public LivingEntity
{
public:
    //item dropitem
    Object* dropItem;
public:
    Monster(std::string name, float hp, float attackDamage, float exp, int money , Object* object);
    ~Monster();

    void UseItem(int key, LivingEntity* target);
    void OnDamaged(float damage);
    float GetExp();

    void Action(int key, LivingEntity& target);
    Object* DropItem();
};


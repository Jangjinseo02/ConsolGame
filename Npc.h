#pragma once
#include "LivingEntity.h"
class Npc :
    public LivingEntity
{
    int price[5];
    int buyPrice[5];
public:
    Npc(std::string name);
    ~Npc();

    void OnDamaged(float damage);
    void OpenInventory();

    int BuyPrice(int key);
    int SellPrice(int key);
};


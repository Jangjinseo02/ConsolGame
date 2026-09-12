#pragma once
#include "LivingEntity.h"
#include "Object.h"

class Player : public LivingEntity
{
private:
	int level;
public:
	Player(std::string name, float hp, float attackDamage);

	bool Get(Object& obj);
	void OnDamaged(float damage);
	void OpenInventory();

	void SetExp(float value);
	void LevelUp();
};


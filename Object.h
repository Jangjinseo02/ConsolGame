#pragma once
#include <string>

class LivingEntity;

class Object
{
protected:
	int type; // hp type = 0, damage type = 1, 
	std::string name;

public:
	Object();
	virtual void Use(LivingEntity& target);
	std::string ReName();
	int Type();
};


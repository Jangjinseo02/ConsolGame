#pragma once
#include <string>

class Object;
class Npc;

class LivingEntity
{
protected:
	std::string name;
	int money;
	float maxHp;
	float hp;
	float attackDamage;
	float exp;
	bool dead;

	Object* inventory[5]; //
	bool isInventory[5] = { false };
	bool isOpen = false;
	int maxinven;
public:

	LivingEntity(std::string name, float hp, float attackDamage, float exp);
	~LivingEntity();

	virtual bool Get(Object& obj);
	//모든 생명체는 공격 당한다.
	virtual void OnDamaged(float damage);
	//아이템 사용 행동
	virtual void Action(int key, LivingEntity& target);
	//실제 아이템 사용
	virtual void UseItem(int key, LivingEntity* target);
	virtual void OpenInventory();

	//player는 npc와 아이템을 사고판다.
	void BuyItem(Npc& target, int key);
	void SellItem(Npc& target, int key);

	//모든 생명체는 공격가능하다.
	void Attack(LivingEntity& target);
	bool Dead();
	bool OpenInven();
	
	Object* FindInventory(int key);
	
	void Restore(float value);

};


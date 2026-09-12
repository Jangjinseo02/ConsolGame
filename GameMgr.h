#pragma once
#include "Player.h"
#include "Monster.h"
#include "Npc.h"
#include "IT_Restore.h"
#include "IT_Curse.h"
#include <map>

class GameMgr
{
	typedef std::map<int, Object*> ITEM_MAP;

	ITEM_MAP m_ITMap; //아이템 할당, 랜덤으로 받아오기.

	Player* player;
	Monster* monster;
	Npc* npc;
	Object* object;

	int keyCount;
	
public:
	GameMgr();
	~GameMgr();

	LivingEntity* ReturnPlayer();
	bool KeyCheck(); //키보드 입력이 있는지 체크한다.
	void Print(); //대화를 출력한다.
	void OnUpdate(); //게임을 갱신한다.

	void Add(int key, Object* value);
	Object* Find(int key);
	void Delete(int key);
};


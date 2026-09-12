#include "GameMgr.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

GameMgr::GameMgr() {
	keyCount = 0;
	std::string name = "Player";
	float hp = 100.0f;
	float atttackDamage = 10.0f;

	player = new Player(name, hp, atttackDamage);
	
	Add(0, new IT_Restore());
	Add(1, new IT_Curse());

	monster = NULL;
}

GameMgr::~GameMgr() {
	delete player;
	
	for (int i = 0; i < 2; i++) {
		Delete(i);
	}
	m_ITMap.clear();
}

LivingEntity* GameMgr::ReturnPlayer() {
	return player;
}

bool GameMgr::KeyCheck() {
	char key = -1;
	std::cin >> key;

	if (keyCount >=0 && keyCount < 1) {

		keyCount += 1;

		switch (key)
		{
		case 97: // a : 공격
			if (monster)
				player->Attack(*monster);
			else if (npc)
				player->Attack(*npc);
			break;
		case 98: // b : 인벤토리 열기
			player->OpenInventory();
			KeyCheck();
			break;
		case 99: // c : 아이템 획득
			if (monster && monster->Dead())
				if (monster->DropItem())
					player->Get(*(monster->DropItem()));
				else
					printf("몬스터가 지닌 아이템이 존재하지 않습니다. \n아이템을 획득하지 못했습니다.\n");
			else if (Find(2)) {
				player->Get(*Find(2));
			}	
			else
				printf("아이템을 획득하지 못했습니다.\n");
			break;
		case 100:
			if (npc) {
				npc->OpenInventory();
				KeyCheck();
			}
			break;
		case 101:
			if (npc) {
				player->OpenInventory();
				KeyCheck();
			}
			break;
		default:
			printf("아무런 행동을 하지 않았습니다.\n");
			break;
		}

		if (Find(2))
			m_ITMap.erase(2);
		if (npc) {
			delete npc;
			npc = NULL;
		}
			
		
	}
	else {
		keyCount += 1;

		//인벤토리에 대한 행위 1~5
		if (key > 48 && key <= 53) {
			
			if (npc) {
				if (npc->OpenInven())
					player->BuyItem(*npc, key - 49);
				else if (player->OpenInven())
					player->SellItem(*npc, key - 49);
			}
			else
				player->Action(key - 49, *monster);
		}
		else {
			printf("인벤토리를 나갑니다.\n");
		}
	}

	keyCount = 0;
	return key;
}
void GameMgr::Print() {

}
void  GameMgr::OnUpdate() {

	//system("cls");
	int a = rand() % 10;

	if (monster == NULL && a >= 7) {
		printf("몬스터가 나타났습니다. \n");

		int ran = rand() % 2;

		if (a == 7) {
			monster = new Monster("고블린", 30, 5, 15, 5 ,Find(ran));
			monster->Get(*(monster->DropItem()));
		}
		else if (a == 8) {
			monster = new Monster("오크", 50, 15, 30, 20 , Find(ran));
			monster->Get(*(monster->DropItem()));
		}
		else if (a == 9) {
			monster = new Monster("트롤", 60, 30, 50, 50 ,Find(ran));
			monster->Get(*(monster->DropItem()));
		}
	}

	if (monster != NULL) {
		printf("어떤 행동을 하시겠습니까? \n a : 공격, b : 인벤토리\n");
		KeyCheck();

		Sleep(1000);

		if (monster != NULL && monster->Dead()) {
			printf("아이템을 획득하시겠습니까? \n c : 획득\n");
			KeyCheck();

			player->SetExp(monster->GetExp());

			delete monster;
			monster = NULL;
		}
		else {
			monster->Action('1', *player);
		}
	}
	else {
		int ran = rand() % 9;
		if (ran >= 7) {
			printf("아이템을 발견하였습니다. \n어떤 행동을 하시겠습니까? \n a : 공격, b : 인벤토리, c : 획득 \n");

			Add(2, Find(ran / 8));
		}
		else if (ran == 6) {
			npc = new Npc("상점 주인");
			for (int i = 0; i < 5; i++) {
				int ran = rand() % 2;
				npc->Get(*Find(ran));
			}
			printf("상점 주인과 만났습니다.\n 어떤 행동을 하시겠습니까? \n a : 공격, b : 인벤토리, c : 획득, d : 상점 구매, e : 상점 판매 \n");
		}
		else
			printf("아무일도 없었습니다.\n어떤 행동을 하시겠습니까? \n a : 공격, b : 인벤토리, c : 획득 \n");
		
		KeyCheck();
		player->SetExp(10); // originexp = 10;
	}

	if (player->Dead()) {
		printf("=================================== \n당신은 더이상 나아갈 수 없습니다.\n =================================== \n");
		return;
	}

	printf("=================================== \n당신은 나아갑니다.\n =================================== \n");

	Sleep(1000);

	

}


void GameMgr::Add(int key, Object* value) {
	m_ITMap[key] = value;
}

Object* GameMgr::Find(int key) {
	return m_ITMap[key];
}

void GameMgr::Delete(int key) {
	ITEM_MAP::iterator it = m_ITMap.find(key);
	if (it != m_ITMap.end()) {
		delete it->second;
		m_ITMap.erase(it);
	}
}
#include "Player.h"
#include "GameMgr.h"

void main() {
	GameMgr mgr;
	
	LivingEntity* player = mgr.ReturnPlayer();
	
	while (!((*player).Dead())) {

		mgr.OnUpdate();		
	}
}
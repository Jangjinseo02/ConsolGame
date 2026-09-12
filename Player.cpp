#include "Player.h"

Player::Player(std::string name, float hp, float attackDamage) : LivingEntity(name, hp, attackDamage, 0) {
	level = 1;
}

bool Player::Get(Object& obj) {
	if (LivingEntity::Get(obj)) {
		printf("아이템을 획득하였습니다. \t 획득한 아이템 : %s\n", obj.ReName().c_str());
		return true;
	}
		
	printf("아이템을 획득하지 못하였습니다.\n");
	return false;
}

void Player::OnDamaged(float damage) {
	LivingEntity::OnDamaged(damage);

	if (hp <= 0) {
		dead = true;
		printf("Player Die : %d\n", dead);
	}
}

void Player::OpenInventory()
{
	LivingEntity::OpenInventory();

	printf("====================================\n사용할 아이템을 선택해주세요.\n====================================\n");
	printf("나가려면 아무키나 입력해주세요.\n");
}

//경험치 획득
void Player::SetExp(float value) {
	exp = exp + value >= 100 ? 100 : exp + value;
	printf("%f 경험치를 획득하셨습니다. \n", value);
	printf("현재 경험치 : %f \n", exp);

	if (exp >= 100) {
		LevelUp();
	}
}

//레벨업
void Player::LevelUp() {
	level += 1;
	hp = maxHp;
	attackDamage += 0.5f * level;
	exp = 0;
	printf("레벨이 증가합니다. \t 현재 레벨 : %d \t 현재 공격력 : %f \n", level, attackDamage);
	printf("체력을 모두 회복하였습니다. \n");
}


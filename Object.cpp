#include "Object.h"
#include "LivingEntity.h"

Object::Object() {
	type = 0;
	name = " ";
}

void Object::Use(LivingEntity& target) {
	printf("아이템을 사용하였습니다.\n");
	//item use
}

std::string Object::ReName() {
	return name;
}

int Object::Type() {
	return type;
}
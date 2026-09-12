#include "IT_Curse.h"
#include "LivingEntity.h"

IT_Curse::IT_Curse() {
	name = "Curse";
	type = 2; //피해를 주는 아이템
}

void IT_Curse::Use(LivingEntity& target) {
	Object::Use(target);
	target.OnDamaged(50.0f);	
}
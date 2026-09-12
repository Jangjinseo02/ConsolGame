#include "IT_Restore.h"
#include "LivingEntity.h"

IT_Restore::IT_Restore() {
	name = "Restore";
	type = 1; // 1 == hp type;
}

void IT_Restore::Use(LivingEntity& target) {
	Object::Use(target);
	target.Restore(30);
}
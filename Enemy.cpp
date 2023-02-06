#include "Enemy.h"
#include <stdio.h>

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Melee ,
	&Enemy::Shot ,
	&Enemy::Leave
};

Enemy::Enemy() {
	Initialize();
}

Enemy::~Enemy() {

}

void Enemy::Initialize() {
	phase_ = EnemyState::MELEE;
}


void Enemy::Update() {

	(this->*spFuncTable[static_cast<size_t>(phase_)])();

}

void Enemy::Draw() {


}

void Enemy::Melee() {

	printf("‹ßÚUŒ‚‚ğ‚µ‚Ü‚µ‚½\n");

	phase_ = EnemyState::SHOT;

}

void Enemy::Shot() {

	printf("ËŒ‚UŒ‚‚ğ‚µ‚Ü‚µ‚½\n");

	phase_ = EnemyState::LEAVE;

}

void Enemy::Leave() {

	printf("—£’E‚µ‚Ü‚µ‚½\n");

	phase_ = EnemyState::MELEE;

}

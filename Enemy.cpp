#include "Enemy.h"
#include <stdio.h>

int Enemy::isAlive_ = true;
int Enemy::sequense_ = 0;

Enemy::Enemy() {
	sequense_++;

	Initialize();
}

Enemy::~Enemy() {

}

void Enemy::Initialize() {
	id_ = sequense_;
}

void Enemy::Update() {

	printf("%d�Ԗڂ̓G��|���܂����H\n" , id_);
	printf("�|��:1\n");
	printf("�|���Ȃ�:0\n");

	scanf_s("%d" , &key_);

	if (key_ == 1) {
		isAlive_ = false;
	}

}

void Enemy::Draw() {

	if (isAlive_==true) {
		printf("�����Ă�\n");
	}
	else {
		printf("����ł�\n");
	}

}

void Enemy::SetIsAlive(int isAlive) {
	isAlive_ = isAlive;
}
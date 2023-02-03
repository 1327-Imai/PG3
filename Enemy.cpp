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

	printf("%d”Ô–Ú‚Ì“G‚ğ“|‚µ‚Ü‚·‚©H\n" , id_);
	printf("“|‚·:1\n");
	printf("“|‚³‚È‚¢:0\n");

	scanf_s("%d" , &key_);

	if (key_ == 1) {
		isAlive_ = false;
	}

}

void Enemy::Draw() {

	if (isAlive_==true) {
		printf("¶‚«‚Ä‚é\n");
	}
	else {
		printf("€‚ñ‚Å‚é\n");
	}

}

void Enemy::SetIsAlive(int isAlive) {
	isAlive_ = isAlive;
}
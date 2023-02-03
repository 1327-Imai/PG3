#include <stdio.h>
#include "Enemy.h"

int main() {

	const int enemyNum = 3;
	Enemy* enemy[enemyNum];

	while (true) {
		enemy[0]->SetIsAlive(true);

		for (int i = 0; i < enemyNum; i++) {
			enemy[i] = new Enemy;
		}

		for (int i = 0; i < enemyNum; i++) {

			enemy[i]->Update();

		}

		for (int i = 0; i < enemyNum; i++) {

			enemy[i]->Draw();

		}

		for (int i = 0; i < enemyNum; i++) {
			delete enemy[i];
		}

	}

	return 0;
}
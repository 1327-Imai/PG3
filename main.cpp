#include <stdio.h>
#include "Enemy.h"

int main() {

	Enemy* enemy = new Enemy;

	while (true) {
		enemy->Update();

		enemy->Draw();
	}

	return 0;
}
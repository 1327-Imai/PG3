#pragma once

enum class EnemyState {
	MELEE,
	SHOT,
	LEAVE
};

class Enemy {
public:

	Enemy();

	~Enemy();

	void Initialize();

	void Update();

	void Draw();

	void Melee();

	void Shot();

	void Leave();

private:
	EnemyState phase_;

	static void (Enemy::* spFuncTable[])();
};


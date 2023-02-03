#pragma once
class Enemy {
public:

	Enemy();

	~Enemy();

	void Initialize();

	void Update();

	void Draw();

	void SetIsAlive(int isAlive);

private:
	static int isAlive_;
	static int sequense_;

	int key_;
	int id_;
};


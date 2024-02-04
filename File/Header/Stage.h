#pragma once
#include"./File/Header/Enemy.h"
#include"./File/Header/Player.h"
class Stage
{
private:
	bool isShot = false;
public:
	Stage();
	~Stage();
	void Initialize();
	void Update(char* keys, char* preKeys,bool isInitialize);
	void Draw();
	Player* player;
	Enemy* enemy1;
	Enemy* enemy2;
};


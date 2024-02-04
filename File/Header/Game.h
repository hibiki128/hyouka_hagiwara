#pragma once
#include"./File/Header/Stage.h"
#include"./File/Header/SceneChange.h"
class Game
{
private:
	enum SCENE {
		TITLE,
		GAME,
	};
	int nowScene_;
	bool isInitialize = false;
public:
	Game();
	~Game();
	void Initialize();
	void Update(char* keys, char* preKeys);
	void Draw(); 

	Stage* stage;
	SceneChange* SC;
};
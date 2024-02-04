#pragma once
#include"./File/Header/Easing.h"
#include"./Vector2.h"
#include"Novice.h"
class SceneChange
{
private:
	Vector2 StartPos_;
	Vector2 EndPos_;
	Vector2 lt_;
	Vector2 lb_;
	Vector2 rt_;
	Vector2 rb_;
	float t_;
	easename EaseName_;
	bool isSceneChange1_;
	bool isSceneChange2_;
	int SCENE_;
public:
	SceneChange();
	~SceneChange();
	void Update();
	void Draw();
	bool GetChange1() { return isSceneChange1_; };
	bool GetChange2() { return isSceneChange2_; };
	float GetT() { return t_; };
	void SetChange1(bool isSceneChange1);
};


#pragma once
#include"Vector2.h"
class Enemy
{
private:
	Vector2 pos_;
	float speed_;
	float radius_;
	bool isAlive_;
	int hp_;
	int enemy_;
public:
	Enemy(Vector2 pos, float speed, float radius,int hp);
	~Enemy();
	void Initialize();
	void Update();
	void Draw();
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	float GetRadius() { return radius_; };
	float GetSpeed() { return speed_; };
	bool GetAlive() { return isAlive_; };
	int GetHp() { return hp_; };
	void SetPos(Vector2 pos);
	void SetRadius(float radius);
	void SetSpeed(float speed);
	void SetAlive(bool isAlive);
	void SetHp(int hp);
};


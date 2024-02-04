#pragma once
#include"Novice.h"
#include"Vector2.h"
#include"./File/Header/Bullet.h"
class Player
{
public:
	Player(Vector2 pos, int speed, float radius);
	~Player();
	void Initialize();
	void Update(char* keys, char* preKeys);
	void Draw();
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	float GetRadius() { return radius_; };
	int GetSpeed() { return speed_; };
	bool GetAlive() { return isAlive_; };
	void SetPos(Vector2 pos);
	void SetRadius(float radius);
	void SetSpeed(int speed);
	void SetAlive(bool isAlive);
	Bullet* bullet_[BulletNum];

private:
	Vector2 pos_;
	float radius_;
	int speed_;
	int player_;
	bool isAlive_;
};


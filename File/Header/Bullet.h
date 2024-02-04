#pragma once
#include "Vector2.h"
#include"Novice.h"
#define BulletNum (10)
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Initialize();
	void Update();
	void Draw();
	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	float GetRadius() { return radius_; };
	float GetSpeed() { return speed_; };
	bool GetShot() { return isShot_; };
	void SetPos(Vector2 pos);
	void SetRadius(float radius);
	void SetSpeed(float speed);
	void SetShot(bool isShot);

protected:
	Vector2 pos_;
	float radius_;
	float speed_;
	bool isShot_;
	int bullet_;
};


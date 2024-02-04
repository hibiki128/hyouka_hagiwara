#include "./File/Header/Bullet.h"

Bullet::Bullet()
{
	pos_ = { 1300.0f,1000.0f };
	radius_ = 10.0f;
	speed_ = 10.0f;
	isShot_ = false;
	bullet_ = Novice::LoadTexture("./Resources/bullet.png");
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
}

void Bullet::Update()
{
	if (isShot_ == true) {
		pos_.y -= speed_;
	}
	if (pos_.y <= 0) {
		isShot_ = false;
	}
	if (isShot_ == false) {
		pos_ = { 1300.0f,1000.0f };
	}
}

void Bullet::Draw()
{
	if (isShot_ == true) {
		Novice::DrawSprite(int(pos_.x - radius_), int(pos_.y - radius_), bullet_, 1, 1, 0.0f, WHITE);
	}
}

void Bullet::SetPos(Vector2 pos)
{
	pos_.x = pos.x;
	pos_.y = pos.y;
}

void Bullet::SetRadius(float radius)
{
	radius_ = radius;
}

void Bullet::SetSpeed(float speed)
{
	speed_ = speed;
}

void Bullet::SetShot(bool isShot)
{
	isShot_ = isShot;
}

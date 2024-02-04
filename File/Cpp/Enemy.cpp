#include "./File/Header/Enemy.h"
#include"Novice.h"

Enemy::Enemy(Vector2 pos, float speed, float radius,int hp)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	isAlive_ = true;
	hp_ = hp;
	enemy_ = Novice::LoadTexture("./Resources/enemy.png");
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	
}

void Enemy::Update()
{
	if (isAlive_ == true) {
		pos_.x += speed_;
		if (pos_.x > 1280 - radius_ || pos_.x < 0 + radius_) {
			speed_ = -speed_;
		}
	}
	if (hp_ > 0) {
		isAlive_ = true;
	}
	else {
		isAlive_ = false;
	}
}

void Enemy::Draw()
{
	if (isAlive_ == true) {
		Novice::DrawSprite(int(pos_.x - radius_), int(pos_.y - radius_), enemy_, 1, 1, 0.0f, WHITE);
	}
}

void Enemy::SetPos(Vector2 pos)
{
	pos_.x = pos.x;
	pos_.y = pos.y;
}

void Enemy::SetRadius(float radius)
{
	radius_ = radius;
}

void Enemy::SetSpeed(float speed)
{
	speed_ = speed;
}

void Enemy::SetAlive(bool isAlive)
{
	isAlive_ = isAlive;
}

void Enemy::SetHp(int hp)
{
	hp_ = hp;
}

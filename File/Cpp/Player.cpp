#include "./File/Header/Player.h"

Player::Player(Vector2 pos, int speed, float radius)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	for (int i = 0; i < BulletNum; i++) {
		bullet_[i] = new Bullet;
	}
	isAlive_ = true;
	player_ = Novice::LoadTexture("./Resources/player.png");
}

Player::~Player()
{
	for (int i = 0; i < BulletNum; i++) {
		delete bullet_[i];
	}
}

void Player::Initialize()
{
	for (int i = 0; i < BulletNum; i++) {
		bullet_[i]->Initialize();
	}
}

void Player::Update(char* keys, char* preKeys)
{
	if (isAlive_ == true) {
		int cooltime = 0;
		for (int i = 0; i < BulletNum; i++) {
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && bullet_[i]->GetShot() == false && cooltime == 0) {
				bullet_[i]->SetPos(pos_);
				bullet_[i]->SetShot(true);
				cooltime = 3;
			}
			bullet_[i]->Update();
		}
		if (cooltime > 0) {
			cooltime -= 1;
		}
		if (keys[DIK_W]) {
			pos_.y -= speed_;
		}
		if (keys[DIK_S]) {
			pos_.y += speed_;
		}
		if (keys[DIK_A]) {
			pos_.x -= speed_;
		}
		if (keys[DIK_D]) {
			pos_.x += speed_;
		}
		if (pos_.x > 1280 - radius_) {
			pos_.x = float(1280 - radius_);
		}
		if (pos_.x < 0 + radius_) {
			pos_.x = float(0 + radius_);
		}
		if (pos_.y > 720 - radius_) {
			pos_.y = float(720 - radius_);
		}
		if (pos_.y < 0 + radius_) {
			pos_.y = float(0 + radius_);
		}
	}
}

void Player::Draw()
{
	if (isAlive_ == true) {
		for (int i = 0; i < 10; i++) {
			bullet_[i]->Draw();
		}
		Novice::DrawSprite(int(pos_.x - radius_), int(pos_.y - radius_), player_, 1, 1, 0.0f, WHITE);
	}
}

void Player::SetPos(Vector2 pos)
{
	pos_.x = pos.x;
	pos_.y = pos.y;
}

void Player::SetRadius(float radius)
{
	radius_ = radius;
}

void Player::SetSpeed(int speed)
{
	speed_ = speed;
}

void Player::SetAlive(bool isAlive)
{
	isAlive_ = isAlive;
}

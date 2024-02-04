#include "./File/Header/Stage.h"

Stage::Stage()
{
	player = new Player({ 640,600 }, 7, 50);
	enemy1 = new Enemy({ 600,250 }, 9, 25, 10);
	enemy2 = new Enemy({ 400,100 }, 9, 25, 10);
}

Stage::~Stage()
{
	delete player;
	delete enemy1;
	delete enemy2;
}

void Stage::Initialize()
{
	player->Initialize();
	enemy1->Initialize();
	enemy2->Initialize();
}

void Stage::Update(char* keys, char* preKeys, bool isInitialize)
{
	player->Update(keys, preKeys);
	enemy1->Update();
	enemy2->Update();
	for (int i = 0; i < BulletNum; i++) {
		if (enemy1->GetAlive() == true && player->GetAlive() == true) {
			float distX = player->bullet_[i]->GetPosX() - enemy1->GetPosX();
			float distY = player->bullet_[i]->GetPosY() - enemy1->GetPosY();
			float dist = (distX * distX) + (distY * distY);
			float radius = player->bullet_[i]->GetRadius() + enemy1->GetRadius();
			if (dist <= radius * radius) {
				enemy1->SetHp(enemy1->GetHp() - 1);
				player->bullet_[i]->SetShot(false);
			}
		}
		if (enemy2->GetAlive() == true && player->GetAlive() == true) {
			float distX = player->bullet_[i]->GetPosX() - enemy2->GetPosX();
			float distY = player->bullet_[i]->GetPosY() - enemy2->GetPosY();
			float dist = (distX * distX) + (distY * distY);
			float radius = player->bullet_[i]->GetRadius() + enemy2->GetRadius();
			if (dist <= radius * radius) {
				enemy2->SetHp(enemy2->GetHp() - 1);
				player->bullet_[i]->SetShot(false);
			}
		}
	}
	if (enemy1->GetAlive() == true && player->GetAlive() == true) {
		float distX = player->GetPosX() - enemy1->GetPosX();
		float distY = player->GetPosY() - enemy1->GetPosY();
		float dist = (distX * distX) + (distY * distY);
		float radius = player->GetRadius() + enemy1->GetRadius();
		if (dist <= radius * radius) {
			enemy1->SetHp(enemy1->GetHp() - 1);
			player->SetAlive(false);
		}
	}
	if (enemy2->GetAlive() == true && player->GetAlive() == true) {
		float distX = player->GetPosX() - enemy2->GetPosX();
		float distY = player->GetPosY() - enemy2->GetPosY();
		float dist = (distX * distX) + (distY * distY);
		float radius = player->GetRadius() + enemy2->GetRadius();
		if (dist <= radius * radius) {
			enemy2->SetHp(enemy2->GetHp() - 1);
			player->SetAlive(false);
		}
	}
	Novice::ScreenPrintf(0, 0, "enemy1 hp = %d", enemy1->GetHp());
	Novice::ScreenPrintf(0, 20, "enemy2 hp = %d", enemy2->GetHp());
	Novice::ScreenPrintf(0, 40, "WASD : player Move");
	Novice::ScreenPrintf(0, 60, "SPACE : shot");
	Novice::ScreenPrintf(0, 80, "R : respawn");
	if (isInitialize == true || (keys[DIK_R] && preKeys[DIK_R] == 0)) {
		enemy1->SetHp(10);
		enemy2->SetHp(10);
		player->SetAlive(true);
		player->SetPos({ 640,600 });
	}
}

void Stage::Draw()
{
	player->Draw();
	enemy1->Draw();
	enemy2->Draw();
}

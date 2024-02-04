#include"./File/Header/Game.h"

Game::Game()
{
	stage = new Stage();
	SC = new SceneChange();
	nowScene_ = TITLE;
}

Game::~Game()
{
	delete stage;
	delete SC;
}

void Game::Initialize()
{
	stage->Initialize();
}

void Game::Update(char* keys, char* preKeys)
{
	switch (nowScene_)
	{
	case TITLE:
		if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
			SC->SetChange1(true);
		}
		if (SC->GetT() >= 0.99f && SC->GetChange1() == true) {
			nowScene_ = GAME;
			isInitialize = true;
		}
		break;
	case GAME:
		stage->Update(keys, preKeys, isInitialize);
		isInitialize = false;
		if (stage->enemy1->GetAlive() == false && stage->enemy2->GetAlive() == false) {
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
				SC->SetChange1(true);
			}
			if (SC->GetT() >= 0.99f && SC->GetChange1() == true) {
				nowScene_ = TITLE;
			}
		}
		break;
	}
	SC->Update();
}

void Game::Draw()
{
	switch (nowScene_)
	{
	case TITLE:
		Novice::ScreenPrintf(570, 360, "ENTER is START");
		break;
	case GAME:
		stage->Draw();
		if (stage->enemy1->GetAlive() == false && stage->enemy2->GetAlive() == false) {
			Novice::ScreenPrintf(510, 345, "GAME CLEAR!!");
			Novice::ScreenPrintf(500, 360, "ENTER is TITLE");
		}
		break;
	}
	SC->Draw();
}

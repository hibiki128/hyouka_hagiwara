#include "./File/Header/SceneChange.h"

SceneChange::SceneChange()
{
	StartPos_ = { 0,0 };
	EndPos_ = { 0,0 };
	lt_ = { 0,0 };
	lb_ = { 0,0 };
	rt_ = { 0,0 };
	rb_ = { 0,0 };
	isSceneChange1_ = false;
	isSceneChange2_ = false;
	t_ = 0;
	SCENE_ = Novice::LoadTexture("./NoviceResources/white1x1.png");
}

SceneChange::~SceneChange()
{
}

void SceneChange::Update()
{
	if (isSceneChange1_ == true) {
		t_ += 0.01f;
		StartPos_.x = 0;
		EndPos_.x = StartPos_.x + 1280;
		EaseName_ = InQuart;
		EaseingX(EaseName_, rt_.x, StartPos_.x, EndPos_.x, t_);
		EaseingX(EaseName_, rb_.x, StartPos_.x, EndPos_.x, t_);
		isSceneChange2_ = true;
		if (t_ >= 1) {
			isSceneChange1_ = false;
			t_ = 0.0f;
		}
	}
	if (isSceneChange1_ == false && isSceneChange2_ == true) {
		t_ += 0.01f;
		StartPos_.x = 0;
		EndPos_.x = StartPos_.x + 1280;
		EaseName_ = OutQuart;
		EaseingX(EaseName_, lt_.x, StartPos_.x, EndPos_.x, t_);
		EaseingX(EaseName_, lb_.x, StartPos_.x, EndPos_.x, t_);
		if (t_ >= 1) {
			isSceneChange2_ = false;
			t_ = 0.0f;
		}
	}
	if (isSceneChange1_ == false && isSceneChange2_ == false) {
		lt_.x = 0;
		lt_.y = 0;
		rt_.x = 0;
		rt_.y = 0;
		lb_.x = 0;
		lb_.y = 720;
		rb_.x = 0;
		rb_.y = 720;
	}
}

void SceneChange::Draw()
{
	Novice::DrawQuad(int(lt_.x), int(lt_.y), int(rt_.x), int(rt_.y), int(lb_.x), int(lb_.y), int(rb_.x), int(rb_.y), 0, 0, 1, 1, SCENE_, WHITE);
}

void SceneChange::SetChange1(bool isSceneChange1)
{
	isSceneChange1_ = isSceneChange1;
}

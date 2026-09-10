#include "ClearScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Image.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hClearpic_(-1)
{
}

void ClearScene::Initialize()
{
	hClearpic_ = Image::Load("Clear.png");
	assert(hClearpic_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_P))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hClearpic_, transform_);
	Image::Draw(hClearpic_);
}

void ClearScene::Release()
{
}

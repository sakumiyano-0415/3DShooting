#include "PlayScene.h"
#include "Engine/Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Engine/Camera.h"
#include "Engine/SceneManager.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene"), hModel_(-1)
{
}

void PlayScene::Initialize()
{
	Instantiate<Player>(this); //Playerのインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Enemy>(this);
	//Instantiate<Bullet>(this);
	//Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(0.0f, 5.0f, -10.0f));
	Camera::SetTarget(XMFLOAT3(0.0f, 3.0f, 10.0f));
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr){
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}

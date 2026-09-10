#include "Player.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h"
#include "Bullet.h"

Player::Player(GameObject* parent)
// 親のポインタ、オブジェクトの名前
	:GameObject(parent, "Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("blasterO.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f, 0.0f, 0.0f };
	transform_.rotate_ = { 0.0f, 180.0f, 0.0f };
}

void Player::Update()
{
	//tr_.scale_ = { 1.0f, 0.5f, 1.0f };
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		transform_.position_.x = transform_.position_.x - 0.25f;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		transform_.position_.x = transform_.position_.x + 0.25f;
	}
	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_S))
	{
		transform_.position_.y = transform_.position_.y - 0.25f;
	}
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_W))
	{
		transform_.position_.y = transform_.position_.y + 0.25f;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet *pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

#include "Enemy.h"
#include "Engine//SphereCollider.h"
#include "Engine\\Model.h"



Enemy::Enemy(GameObject* parent)
	: GameObject(parent, "Enemy"),hModel_(-1)
{
	
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("teki.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f, -4.0f, 30.0f };
	transform_.rotate_ = { 0.0f, -70.0f, 0.0f }; 

	// 移動設定
	moveDir_ = { 1.0f, 0.7f};
	speed_ = 0.1f; //大きくすると高速化
	moveRange_ = 15.0f; // 広範囲移動

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
}

void Enemy::Update()
{
	// 移動
	transform_.position_.x += moveDir_.x * speed_;
	transform_.position_.y += moveDir_.y * speed_;


	// 範囲外に行ったら反転
	if (transform_.position_.x > moveRange_ || transform_.position_.x < -moveRange_)
	{
		moveDir_.x *= -1;
	}

	if (transform_.position_.y > moveRange_ || transform_.position_.y < -moveRange_)
	{
		moveDir_.y *= -1;
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe(); // ばれっと消す
		KillMe(); // 自分も消す
	}
}

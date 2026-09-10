#include "Bullet.h"
#include "Engine\\Model.h"
#include "Player.h"
#include "Engine//SphereCollider.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1), speed_(0.5f)
{
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("tama.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = { 0.3f, 0.3f, 0.3f };
	Player* player = (Player*)GetParent();
	transform_.position_ = player->GetPosition();
	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.5f), 1.0f);
	AddCollider(collider);
}

void Bullet::Update()
{
	transform_.position_.z = transform_.position_.z + speed_;
	if (transform_.position_.z > 50.0f)
	{
		KillMe();
	}
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}

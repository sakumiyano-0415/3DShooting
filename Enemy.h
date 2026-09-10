#pragma once
#include "Engine\\GameObject.h"
class Enemy :
    public GameObject
{
public:
    Enemy(GameObject* parent);
    ~Enemy();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;
    void OnCollision(GameObject* pTarget);
private:
    int hModel_; //モデルのハンドル
    XMFLOAT2 moveDir_;   // 移動方向
    float speed_;        // 移動速度
    float moveRange_;    // 移動範囲
};


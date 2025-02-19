#pragma once
#include "Pawn.h"
#include "MeshComponent.h"
#include "PlayerMovement.h"
#include "CollisionComponent.h"

#include "HandSocket.h"

class Level;

class PlayerPawn : public Pawn
{
	MeshComponent* mesh;
	PlayerMovementComponent* movement;
	CollisionComponent* collision;
	HandSocket* hand;
	Vector2f direction;
	float rotationVelocity;
	float smoothTime;
	
public:
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		Super::SetPosition(_position);
		mesh->GetShape()->SetPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		Super::SetRotation(_rotation);
		mesh->GetShape()->SetRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		Super::SetScale(_scale);
		mesh->GetShape()->SetScale(_scale);
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		Super::SetOrigin(_origin);
		mesh->GetShape()->SetOrigin(_origin);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		mesh->GetShape()->Move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		Super::Rotate(_angle);
		mesh->GetShape()->Rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		Super::Scale(_factor);
		mesh->GetShape()->Scale(_factor);
	}

public:
	PlayerPawn(Level* _level);
	PlayerPawn(const PlayerPawn& _other);

private:
	Actor* GetHand();

public:
	void InitCollision();
	virtual void Construct() override;
	virtual void SetupInputController(Input::InputManager& _inputManager) override;
	void ProcessInput(const Vector2f& _vectorDirection);
	void Rotate(const float _deltaTime);


	virtual void CollisionEnter(const CollisionData& _data);
	virtual void CollisionUpdate(const CollisionData& _data);
	virtual void CollisionExit(const CollisionData& _data){}

	virtual void Tick(const float _deltaTime) override;
};


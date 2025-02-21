#pragma once
#include "Pawn.h"
#include "MeshComponent.h"
#include "CarMovementComponent.h"
#include "CollisionComponent.h"
#include "TriggerBox.h"


class ChooseMapPawn : public Pawn
{
	MeshComponent* mesh;
	CarMovementComponent* movement;
	CollisionComponent* collision;
	float currentRotation;
	TriggerBox* currentTriggerBox;

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
	ChooseMapPawn(Level* _level);
	ChooseMapPawn(const ChooseMapPawn& _other);

public:
	void InitCollision();
	virtual void Construct() override;
	virtual void SetupInputController(Input::InputManager& _inputManager) override;
	void ProcessInput(const Vector2f& _vectorDirection);
	void ComputeRotation();

	virtual void CollisionEnter(const CollisionData& _data);
	virtual void CollisionUpdate(const CollisionData& _data){}
	virtual void CollisionExit(const CollisionData& _data);
	void Tick(const float _deltaTime);
	

private:
	void interactWithTriggerBox();
	void RotatePlayer(const Vector2f& _direction, const float _deltaTime);

};


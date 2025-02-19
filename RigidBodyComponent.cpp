#include "RigidBodyComponent.h"
#include "Actor.h"
#include "DebugLevel.h"

RigidBodyComponent::RigidBodyComponent(Actor* _owner) : Component(_owner)
{
	mass = 20.0f;
	high = 100.0f;
	isFall = false;
	DebugLevel* _level = Cast<DebugLevel>(owner->GetLevel());
	gravity = _level->GetGravity();
	roughness = 0.5f;
	elasticity = 0.5f;
	velocity = Vector2f();
	ownerScale = owner->GetScale();
}


RigidBodyComponent::RigidBodyComponent(Actor* _owner, const RigidBodyComponent& _other) : Component(_owner, _other)
{
	mass = _other.mass;
	high = _other.high;
	isFall = _other.isFall;
	DebugLevel* _level = Cast<DebugLevel>(owner->GetLevel());
	gravity = _level->GetGravity();
	roughness = _other.roughness;
	elasticity = _other.elasticity;
	velocity = Vector2f();
	ownerScale = _other.ownerScale;
}

void RigidBodyComponent::ComputeVelocity(const float _deltaTime)
{
	if (isFall)
	{
		DiscreaseHigh(_deltaTime);
	}

	Vector2f _velocity = velocity * gravity * mass * _deltaTime;


	velocity -= _velocity * _deltaTime;

	if (high == 1)
	{
		ApplyBounce(Vector2f(0, 0), Vector2f(0,0));
	}
}

void RigidBodyComponent::DiscreaseHigh(const float _deltaTime)
{
	const float _high = high * gravity * mass * _deltaTime / 50;
	high -= _high;
	high = high < 1 ? 1 : high;
	isFall = high != 1;
}

void RigidBodyComponent::Rescale()
{
	const float _factor = 1 + (100 * EaseOutQuart(high / 100) * 100) / 100;
	owner->SetScale({ ownerScale.x * _factor / 100,  ownerScale.y * _factor /100});
}

void RigidBodyComponent::Tick(const float _deltaTime)
{
	ComputeVelocity(_deltaTime);
	if (owner->GetName() == "RigidActor")
	{
		LOG(Warning, "ball : " + to_string(high));
	}
	Rescale();
}


void RigidBodyComponent::ApplyBounce(const Vector2f& _normal, const Vector2f& _otherVelocity)
{
	// Calculer la projection de la vitesse sur la normale
	float _dotProduct = (velocity.x + _otherVelocity.x ) * _normal.x + (velocity.y + _otherVelocity.y) * _normal.y;
	high *= _dotProduct;
	// Appliquer le rebond : inverser la composante normale de la vitesse
	velocity -= 2.0f * _dotProduct * _normal;

	// R�duire la vitesse en fonction du facteur de restitution
	velocity *= elasticity;

	// Appliquer la friction � la composante tangentielle
	velocity *= roughness;


	if (abs(velocity.x) < 1.0f)
	{
		velocity.x = 0.0f;
	}

	if (abs(velocity.y) < 1.0f)
	{
		velocity.y = 0.0f;
	}
	
}
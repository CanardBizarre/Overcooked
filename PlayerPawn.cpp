#include "PlayerPawn.h"
#include "Level.h"
#include "InputManager.h"
#include "Utilities.h"

using namespace Input;

PlayerPawn::PlayerPawn(Level* _level) 
	: Pawn(_level, "Keyboard")
{
	mesh = CreateComponent<MeshComponent>(RectangleShapeData(Vector2f(50.0f, 50.0f), "/Characters/Clothes/spritesheet", PNG, false, IntRect(Vector2i(), Vector2i(124,124))));
	movement = CreateComponent<PlayerMovementComponent>();
	collision = CreateComponent<CollisionComponent>();
	movement->SetVelocity({ 200.0f,200.0f });
	InitCollision();
	rotationVelocity = 0.0f;
	smoothTime = 0.1f;
}

PlayerPawn::PlayerPawn(const PlayerPawn& _other) : Pawn(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(*_other.movement);
	mesh = CreateComponent<MeshComponent>(*_other.mesh);
	collision = CreateComponent<CollisionComponent>(*_other.collision);

}

void PlayerPawn::InitCollision()
{
	collision->SetInformation("Player", IS_ALL, CT_BLOCK);
	collision->AddResponses(
	{ 
		{ "KitchenBlock", CT_BLOCK },
		{ "RigidProp", CT_BLOCK },
	});
	SetLayerType(WORLD_DYNAMIC);
}

void PlayerPawn::Construct()
{
	Super::Construct();
	SetZOrder(2);
	mesh->SetOriginAtMiddle();
	GetHand();
}

void PlayerPawn::SetupInputController(Input::InputManager& _inputManager)
{
	ActionMap* _moveInputs = _inputManager.CreateActionMap("PlayerMovement");

	_moveInputs->AddActions(
		{
			new Action("GoUp", ActionData(KeyHold, Z), [&]()
			{
				ProcessInput({0.0f, -1.0f});
			}),
			new Action("GoDown", ActionData(KeyHold, S), [&]()
			{
				ProcessInput({0.0f, 1.0f});
			}),
			new Action("GoLeft", ActionData(KeyHold, Q), [&]()
			{
				ProcessInput({-1.0f, 0.0f});
			}),
			new Action("GoRight", ActionData(KeyHold, D), [&]()
			{
				ProcessInput({1.0f, 0.0f});
			}),


			new Action("RestUp", ActionData(KeyReleased, Z), [&]()
			{
				movement->ResetY();
			}),
			new Action("RestDown", ActionData(KeyReleased, S), [&]()
			{
				movement->ResetY();
			}),
			new Action("RestLeft", ActionData(KeyReleased, Q), [&]()
			{
				movement->ResetX();
			}),
			new Action("RestRight", ActionData(KeyReleased, D), [&]()
			{
				movement->ResetX();
			}),

			new Action("Dash", ActionData(KeyHold, Space), [&]()
			{
				movement->Dash();
			}),
			new Action("TakeObject", ActionData(KeyPressed, E), [&]()
			{
				hand->Action();
			}),
		});
	
	_moveInputs->Enable();
}

void PlayerPawn::ProcessInput(const Vector2f& _vectorDirection)
{
	direction = _vectorDirection;
	movement->ProcessInput(_vectorDirection);

}

void PlayerPawn::Rotate(const float _deltaTime)
{
	if (direction.x == 0.0f && direction.y == 0.0f) return;

	float _targetAngle = atan2f(direction.y, direction.x) * (180.0f / pi);
	float _currentAngle = mesh->GetShape()->GetDrawable()->getRotation().asDegrees();
	float _deltaAngle = _targetAngle - _currentAngle;

	//Secu pour pas tourner a l'infini
	if (_deltaAngle > 180.0f)
	{
		_deltaAngle -= 360.0f;
	}
	else if (_deltaAngle < -180.0f)
	{
		_deltaAngle += 360.0f;
	}

	float _newAngle = _currentAngle + _deltaAngle * _deltaTime * 8;
	SetRotation(degrees(_newAngle));
}

Actor* PlayerPawn::GetHand()
{
	if (GetChildren().size() == 0)
	{
		const float _handOffSet = 20.0f;
		const Vector2f& _pos = GetPosition() + GetForwardVector() * _handOffSet;
		hand = level->SpawnActor<HandSocket>(_pos, _handOffSet);
		AddChild(hand, AT_KEEP_RELATIVE);
	}
	return GetChildrenAtIndex(0);
}

void PlayerPawn::CollisionEnter(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == PROP)
	{
		if (_data.channelName == "KitchenBlock")
		{
			if (_data.response == CT_BLOCK)
			{
				LOG(Warning, "Collision");
				Move(movement->GetDiretion() * -1.5f);
			}
		}
	}
}

void PlayerPawn::CollisionUpdate(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == PROP)
	{
		if (_data.channelName == "KitchenBlock")
		{
			if (_data.response == CT_BLOCK)
			{
				LOG(Warning, "Collision");
				Move(movement->GetDiretion() * -1.5f);
			}
		}
	}
}

void PlayerPawn::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	Rotate(_deltaTime);
}


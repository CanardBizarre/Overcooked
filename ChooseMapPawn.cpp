#include "ChooseMapPawn.h"
#include "Level.h"
#include "InputManager.h"

using namespace Input;

ChooseMapPawn::ChooseMapPawn(Level* _level) : Pawn(_level, "Car")
{
	mesh = CreateComponent<MeshComponent>(RectangleShapeData(Vector2f(100.0f, 50.0f), "Car", PNG));
	mesh->SetOriginAtMiddle();
	movement = CreateComponent<CarMovementComponent>();
	collision = CreateComponent<CollisionComponent>();
	movement->SetVelocity({ 200.0f,200.0f });
	InitCollision();

	SetZOrder(2);
	currentTriggerBox = nullptr;
}

ChooseMapPawn::ChooseMapPawn(const ChooseMapPawn& _other) : Pawn(_other)
{
	movement = CreateComponent<CarMovementComponent>(*_other.movement);
	mesh = CreateComponent<MeshComponent>(*_other.mesh);
	collision = CreateComponent<CollisionComponent>(_other.collision);

	currentTriggerBox = _other.currentTriggerBox;
}

void ChooseMapPawn::InitCollision()
{
	collision->SetInformation("Player", IS_ALL, CT_BLOCK);
	collision->AddResponses(
		{
			{ "TriggerBox", CT_OVERLAP },
		});
	SetLayerType(PLAYER);
}

void ChooseMapPawn::Construct()
{
	Super::Construct();
	SetZOrder(2);
	mesh->SetOriginAtMiddle();
}

void ChooseMapPawn::SetupInputController(Input::InputManager& _inputManager)
{
	ActionMap* _moveInputs = _inputManager.CreateActionMap("CarMovement");

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

			new Action("TakeObject", ActionData(KeyPressed, E), [&]()
			{
				interactWithTriggerBox();
			}),
		});

	_moveInputs->Enable();
}

void ChooseMapPawn::ProcessInput(const Vector2f& _vectorDirection)
{
	movement->ProcessInput(_vectorDirection);
	ComputeRotation();
}

void ChooseMapPawn::ComputeRotation()
{
	const Vector2f& _direction = movement->GetDirection();
	const Vector2f& _pos = GetPosition();
	if (_direction.x + _direction.y == 0.0f) return;
	const float _degrees = atan2f(_direction.y, _direction.x);
	SetRotation(radians(_degrees));
}

void ChooseMapPawn::CollisionEnter(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == WORLD_STATIC)
	{
		if (_data.channelName == "TriggerBox")
		{
			currentTriggerBox = Cast<TriggerBox>(_data.other);
		}
	}
}

void ChooseMapPawn::CollisionExit(const CollisionData& _data)
{
	if (_data.other->GetLayerType() == WORLD_STATIC)
	{
		if (_data.channelName == "TriggerBox")
		{
			currentTriggerBox = nullptr;
		}
	}
}

void ChooseMapPawn::interactWithTriggerBox()
{
	if (!currentTriggerBox) return;
	currentTriggerBox->GetCallback()();
}

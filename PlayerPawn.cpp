#include "PlayerPawn.h"
#include "Level.h"
#include "InputManager.h"

using namespace Input;

PlayerPawn::PlayerPawn(Level* _level) 
	: Pawn(_level, "Keyboard")
{
	mesh = CreateComponent<MeshComponent>(RectangleShapeData(Vector2f(20.0f, 20.0f), "Ball_2", PNG));
	movement = CreateComponent<PlayerMovementComponent>();
	collision = CreateComponent<CollisionComponent>();
	collision->SetInformation("PlayerPawn", IS_ALL, CT_BLOCK);
	collision->AddResponses({ { "RigidProp", CT_BLOCK } });
	SetLayerType(WORLD_DYNAMIC);
	movement->SetVelocity({ 200.0f,200.0f });
}

PlayerPawn::PlayerPawn(const PlayerPawn& _other) : Pawn(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(*_other.movement);
	mesh = CreateComponent<MeshComponent>(*_other.mesh);
}

void PlayerPawn::Construct()
{
	Super::Construct();
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
	movement->ProcessInput(_vectorDirection);
	ComputeRotation();
}

void PlayerPawn::ComputeRotation()
{
	const Vector2f& _direction = movement->GetDirection();
	const Vector2f& _pos = GetPosition();
	if (_direction.x + _direction.y == 0.0f) return;
	const float _degrees = atan2f(_direction.y, _direction.x);
	SetRotation(radians(_degrees));
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
	if (_data.other->GetLayerType() == WORLD_STATIC)
	{
		if (_data.channelName == "RigidProp")
		{
			if (_data.response == CT_BLOCK)
			{
				//movement->SetDirection(-movement->GetDiretion());
			}
		}
	}
}


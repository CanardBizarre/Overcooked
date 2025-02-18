#include "PlayerPawn.h"
#include "Level.h"
#include "InputManager.h"

using namespace Input;

PlayerPawn::PlayerPawn(Level* _level) 
	: Pawn(_level, "Keyboard")
{
	mesh = CreateComponent<MeshComponent>(RectangleShapeData(Vector2f(20.0f, 20.0f), "Ball_2", PNG));
	movement = CreateComponent<PlayerMovementComponent>();
	carry = CreateComponent<CarryComponent>();
	itemOffSet = 20.0f;
}

PlayerPawn::PlayerPawn(const PlayerPawn& _other) : Pawn(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(*_other.movement);
	mesh = CreateComponent<MeshComponent>(*_other.mesh);
	carry = CreateComponent<CarryComponent>(*_other.carry);
	itemOffSet = _other.itemOffSet;
}

void PlayerPawn::Construct()
{
	mesh->SetOriginAtMiddle();
	carry->GetHand();
}

void PlayerPawn::CarryObject(Actor* _object)
{
	carry->Action(_object);
	ComputeHandPosition();
}

void PlayerPawn::SetupInputController(Input::InputManager& _inputManager)
{
	ActionMap* _moveInputs = _inputManager.CreateActionMap("PlayerMovement");

	_moveInputs->AddActions(
		{
			new Action("GoUp", ActionData(KeyHold, Z), [&]()
			{
					LOG(Warning, "up");
				ProcessInput({0.0f, -1.0f});
			}),
			new Action("GoDown", ActionData(KeyHold, S), [&]()
			{
					LOG(Warning, "down");
				ProcessInput({0.0f, 1.0f});
			}),
			new Action("GoLeft", ActionData(KeyHold, Q), [&]()
			{
					LOG(Warning, "left");
				ProcessInput({-1.0f, 0.0f});
			}),
			new Action("GoRight", ActionData(KeyHold, D), [&]()
			{
					LOG(Warning, "right");
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

			new Action("TakeObject", ActionData(KeyHold, Space), [&]()
			{
				movement->Dash();
			}),
		});
	
	_moveInputs->Enable();
}

void PlayerPawn::ProcessInput(const Vector2f& _vectorDirection)
{
	movement->ProcessInput(_vectorDirection);
	ComputeHandPosition();
}

void PlayerPawn::ComputeHandPosition()
{
	const Vector2f& _direction = movement->GetDirection();
	// TODO Rotate Foward


	const Vector2f& _foward = GetForwardVector();
	const Vector2f& _position = GetPosition();
	carry->GetHand()->SetPosition(_position + itemOffSet * _foward);
}

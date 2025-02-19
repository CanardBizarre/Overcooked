#include "PlayerPawn.h"
#include "Level.h"
#include "InputManager.h"

using namespace Input;

PlayerPawn::PlayerPawn(Level* _level) 
	: Pawn(_level, "Keyboard")
{
	mesh = CreateComponent<MeshComponent>(RectangleShapeData(Vector2f(20.0f, 20.0f), "Ball_2", PNG));
	movement = CreateComponent<PlayerMovementComponent>();
}

PlayerPawn::PlayerPawn(const PlayerPawn& _other) : Pawn(_other)
{
	movement = CreateComponent<PlayerMovementComponent>(*_other.movement);
	mesh = CreateComponent<MeshComponent>(*_other.mesh);
}

void PlayerPawn::SetupInputController(Input::InputManager& _inputManager)
{
	ActionMap* _moveInputs = _inputManager.CreateActionMap("PlayerMovement");

	_moveInputs->AddActions(
		{
			new Action("GoUp", ActionData(KeyHold, Z), [&]()
			{
				movement->ProcessInput({0.0f, -1.0f});
			}),
			new Action("GoDown", ActionData(KeyHold, S), [&]()
			{
				movement->ProcessInput({0.0f, 1.0f});
			}),
			new Action("GoLeft", ActionData(KeyHold, Q), [&]()
			{
				movement->ProcessInput({-1.0f, 0.0f});
			}),
			new Action("GoRight", ActionData(KeyHold, D), [&]()
			{
				movement->ProcessInput({1.0f, 0.0f});
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

			new Action("Dash", ActionData(KeyPressed, Space), [&]()
			{
				movement->Dash();
			}),
		});
	
	_moveInputs->Enable();
}

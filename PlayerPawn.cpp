#include "PlayerPawn.h"
#include "Level.h"
#include "InputManager.h"
#include "LevelManager.h"
#include "TimerManager.h"

using namespace Input;

PlayerPawn::PlayerPawn(Level* _level) 
	: Pawn(_level, "Keyboard")
{
	mesh = CreateComponent<MeshComponent>(RectangleShapeData(Vector2f(50.0f, 50.0f), "/Characters/Clothes/spritesheet", PNG, false, IntRect(Vector2i(), Vector2i(124,124))));
	mesh->SetOriginAtMiddle();
	movement = CreateComponent<PlayerMovementComponent>();
	collision = CreateComponent<CollisionComponent>();
	movement->SetVelocity({ 200.0f,200.0f });
	InitCollision();
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
		//TODO CHANGE BLOCK 
		{ "KitchenBlock", CT_OVERLAP },
		{ "RigidProp", CT_BLOCK },
	});
	SetLayerType(PLAYER);
}

void PlayerPawn::Construct()
{
	Super::Construct();
	mesh->SetOriginAtMiddle();
	GetHand();
	SetZOrder(21);

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
				SpawnDashEffect();
			}),
			new Action("TakeObject", ActionData(KeyPressed, E), [&]()
			{
				hand->HandAction();
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
	if (_data.other->GetLayerType() == PROP)
	{
		if (_data.channelName == "KitchenBlock")
		{
			if (_data.response == CT_BLOCK)
			{
				Move(movement->GetDirection() * -1.5f);
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
				Move(movement->GetDirection() * -1.5f);
			}
		}
	}
}

void PlayerPawn::CollisionExit(const CollisionData& _data)
{
	//if (_data.other->GetLayerType() == PROP)
	//{
	//	if (_data.channelName == "KitchenBlock")
	//	{
	//		if (_data.response == CT_BLOCK)
	//		{
	//			LOG(Error, "Exit");
	//			//Move(movement->GetDirection() * -1.5f);
	//		}
	//	}
	//}
}

void PlayerPawn::SetZOrder(const int _zOrder)
{
	Super::SetZOrder(_zOrder);

	GetLevel()->GetCameraManager().SetZOrder(mesh->GetRenderMeshToken(), zOrder);
}

void PlayerPawn::SpawnDashEffect()
{
	if(!movement->Dash()) return;

	Level* _level = M_LEVEL.GetCurrentLevel();

	effect = _level->SpawnActor<DashEffect>(RectangleShapeData(Vector2f(80, 80), "Effects/DashEffect"), "dash");
	AddChild(effect, AT_KEEP_RELATIVE);

	effect->SetPosition(GetPosition() - movement->GetDirection() * 30.0f);
	effect->SetRotation(GetRotation()- degrees(180));
	effect->SetZOrder(1);

	new Timer([&]()
		{
			RemoveChild(effect);
			effect->SetToDelete();
		}, seconds(0.3f), true, false);
}


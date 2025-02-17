#include "DebugLevel.h"
#include "RigidProp.h"
DebugLevel::DebugLevel() : Level("Debug")
{

}

void DebugLevel::InitLevel()
{
	Super::InitLevel();
	SpawnActor<MeshActor>(RectangleShapeData(GetWindowSize(), "BackGround_2", JPG), "BackGround");

	RigidProp* _prop = SpawnActor<RigidProp>(RectangleShapeData({50.0f, 50.0f}), "RigidProp");
	_prop->SetPosition({ 100.0f, 100.0f });
	//_prop->SetZOrder(1)

	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}

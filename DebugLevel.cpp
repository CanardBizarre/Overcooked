#include "DebugLevel.h"
#include "MeshActor.h"
DebugLevel::DebugLevel() : Level("Debug")
{

}

void DebugLevel::InitLevel()
{
	Super::InitLevel();
	SpawnActor<MeshActor>(RectangleShapeData(GetWindowSize(), "BackGround_2", JPG), "BackGround");
	MeshActor* _actor = SpawnActor<MeshActor>(RectangleShapeData(Vector2f(20.0f,20.0f), "Ball_2", PNG), "BackGround");
	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
	//player->CarryObject(_actor);
}

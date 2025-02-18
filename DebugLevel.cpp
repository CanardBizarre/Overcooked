#include "DebugLevel.h"
#include "TestDummy.h"
DebugLevel::DebugLevel() : Level("Debug")
{

}

void DebugLevel::InitLevel()
{
	Super::InitLevel();
	SpawnActor<MeshActor>(RectangleShapeData(GetWindowSize(), "BackGround_2", JPG), "BackGround");
	TestDummy* _dummy = SpawnActor<TestDummy>();
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	player = SpawnActor<PlayerPawn>();                                              
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}

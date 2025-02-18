#include "DebugLevel.h"
#include "TestDummy.h"
#include "WorkPlan.h"
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

	WorkPlan* _prop = SpawnActor<WorkPlan>(Vector2f(50.0f, 50.0f),Vector2f(100.0f, 100.0f));
	_prop->SetPosition({ 100.0f, 100.0f });
	//_prop->SetZOrder(1)

	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}

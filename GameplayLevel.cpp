#include "GameplayLevel.h"
#include "TestDummy.h"


GameplayLevel::GameplayLevel(const string& _name) : Level(_name)
{
}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();

	TestDummy* _dummy = SpawnActor<TestDummy>();
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);
}

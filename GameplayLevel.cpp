#include "GameplayLevel.h"
#include "TestDummy.h"


GameplayLevel::GameplayLevel(const string& _name) : Level(_name)
{
}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();

	Ingredient* _dummy = SpawnActor<Ingredient>(Vector2f(40.0f,40.0f), Vector2f(), Angle(), "Chicken", IT_CHICKEN);
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition(Vector2f(window.getSize()) / 2.0f + Vector2f(10.0f, 0.0f));
	_dummy->SetZOrder(1);

	player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);
	player1->SetZOrder(0);
}

#include "GameplayLevel.h"
#include "TestDummy.h"




GameplayLevel::GameplayLevel(const string& _name, const float _time, const int _maxScore)
	: Level(_name)
{
	time = _time;
	maxScore = _maxScore;

}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();

	HUD* _hud = GetGameMode()->GetHUD();
	canvas = _hud->SpawnWidget<CanvasWidget>();
	canvas->SetDebugMode(true);
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));
	currentScore = 0;

	InitWidget(time);

	TestDummy* _dummy = SpawnActor<TestDummy>();
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);
}

void GameplayLevel::InitWidget(const float _time)
{
}

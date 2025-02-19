#include "GameplayLevel.h"
#include "TestDummy.h"
#include "LabelWidget.h"
#include "ImageWidget.h"
#include "TimerManager.h"

GameplayLevel::GameplayLevel(const string& _name, const float _time, const int _maxScore)
	: Level(_name)
{
	canvas = nullptr;
	player1 = nullptr;
	player2 = nullptr;
	chrono = nullptr;
	time = _time;
	maxScore = _maxScore;
	gravity = 9.8f;
	currentScore = 0;
}

GameplayLevel::~GameplayLevel()
{
	delete chrono;
}

void GameplayLevel::InitLevel()
{
	Super::InitLevel();

	HUD* _hud = GetGameMode()->GetHUD();
	canvas = _hud->SpawnWidget<CanvasWidget>();
	canvas->SetSize(CAST(Vector2f, GetWindowSize()));
	currentScore = 0;

	InitWidgetForChrono(_hud, time);
	InitScore(_hud);

	TestDummy* _dummy = SpawnActor<TestDummy>();
	_dummy->GetMesh()->SetOriginAtMiddle();
	_dummy->SetPosition((Vector2f(window.getSize()) / 2.0f) + Vector2f(10.0f, 0.0f));

	player1 = SpawnActor<PlayerPawn>();
	player1->SetPosition(Vector2f(window.getSize()) / 2.0f);
	GetGameMode()->GetHUD()->AddToViewport(canvas);
}

void GameplayLevel::InitWidgetForChrono(HUD* _hud, const float _time)
{
	const Vector2f& _windowSize = GetWindowSize();
	label = _hud->SpawnWidget<LabelWidget>("null");
	canvas->AddChild(label);
	label->SetFillColor(Color::White);
	label->SetFont("Overcooked", TTF);
	label->SetCharacterSize(32);
	label->SetZOrder(1);
	label->SetOriginAtMiddle();
	label->SetPosition({ _windowSize.x * 0.89f, _windowSize.y * 0.8f });

	ImageWidget* _image = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(150.0f, 75.0f), "UI/Level/timer_slide"));
	canvas->AddChild(_image);
	_image->SetOriginAtMiddle();
	_image->SetPosition({ _windowSize.x * 0.9f, _windowSize.y * 0.8f });
	_image->SetOriginAtMiddle();


	chrono = new Chronometer(_time);

	new Timer([&]() 
		{
			chrono->DecrementCurrentTime();
			label->SetText(chrono->GetTime()); 
		}, seconds(1), true, true);

}

void GameplayLevel::InitScore(HUD* _hud)
{
	const Vector2f& _windowSize = GetWindowSize();
	
	coin = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(62.0f, 62.0f), "UI/Level/coin"));
	canvas->AddChild(coin);
	coin->SetOriginAtMiddle();
	coin->SetPosition(Vector2f(_windowSize.x * 0.1f, _windowSize.y *0.8f));


	scoreLabel = _hud->SpawnWidget<LabelWidget>(to_string(currentScore));
	canvas->AddChild(scoreLabel);
	scoreLabel->SetFillColor(Color(77, 88, 105));
	scoreLabel->SetFont("Overcooked", TTF);
	scoreLabel->SetZOrder(2);
	scoreLabel->SetCharacterSize(32);
	scoreLabel->SetOriginAtMiddle();
	scoreLabel->SetPosition(coin->GetPosition());
}

void GameplayLevel::AddScore(const int _scoreToAdd)
{
	currentScore += _scoreToAdd;
	scoreLabel->SetText(to_string(currentScore));
	scoreLabel->SetOriginAtMiddle();
	scoreLabel->SetPosition(coin->GetPosition());
}


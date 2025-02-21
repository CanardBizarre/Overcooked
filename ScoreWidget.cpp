#include "ScoreWidget.h"
#include "Level.h"
#include "TimerManager.h"

ScoreWidget::ScoreWidget(Level* _level, HUD* _hud, const string& _name)
	: CanvasWidget(_level, _name)
{
	combo = 0;
	score = 0;

	slide = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(170.0f, 70.0f), "UI/blue_slide"));
    coin = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(90.0f, 90.0f), "UI/Sprites/coin"));
	scoreLabel = _hud->SpawnWidget<LabelWidget>("0");
	comboLabel = _hud->SpawnWidget<LabelWidget>("x" + to_string(combo));

	AddChild(slide);
	slide->SetPosition(Vector2f(40.0f, 10.0f));
	slide->SetZOrder(8);

	AddChild(coin);
	coin->SetPosition(Vector2f(0.0f, 0.0f));
	coin->SetZOrder(10);

	AddChild(scoreLabel);
	scoreLabel->SetFillColor(Color::White);
	scoreLabel->SetFont("Overcooked", TTF);
	scoreLabel->SetCharacterSize(40);
	scoreLabel->SetZOrder(9);
	scoreLabel->SetPosition({ 95.0f, 10.0f });

	AddChild(comboLabel);
	comboLabel->SetFillColor(Color::White);
	comboLabel->SetFont("Overcooked", TTF);
	comboLabel->SetCharacterSize(25);
	comboLabel->SetZOrder(9);
	comboLabel->SetPosition({ 165.0f, 47.0f });

	new Timer([&]()
		{
			scoreLabel->SetText(to_string(score));
			comboLabel->SetText("x" + to_string(combo));
			if (combo > 1) comboLabel->SetFillColor(Color::Yellow);
			if (combo == 4) comboLabel->SetFillColor(Color::Red);
		}, seconds(1), true, true);
}

ScoreWidget::ScoreWidget(const ScoreWidget& _other)
	:CanvasWidget(_other)
{

}

ScoreWidget::~ScoreWidget()
{

}

void ScoreWidget::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

}

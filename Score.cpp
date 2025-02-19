#include "Score.h"
#include "CanvasWidget.h"
#include "LabelWidget.h"
#include "TimerManager.h"


Score::Score(HUD* _hud)
{
	score = 0;
	hud = _hud;
}

void Score::InitScore( const Vector2f& _windowSize)
{
	canvasScore = hud->SpawnWidget<CanvasWidget>("CanvasScore");
	canvasScore->SetSize(Vector2f(_windowSize.x / 50, _windowSize.y - _windowSize.y / 4));
	//_canvasScore->SetScale(Vector2f(50, 50));

	ImageWidget* _score = hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(_windowSize.x / 10, _windowSize.x / 10), "UI/Sprites/coin"));
	canvasScore->AddChild(_score);
	cout << "x : " << to_string(canvasScore->GetSize().x) << " y : " << to_string(canvasScore->GetSize().y);
	_score->SetPosition(Vector2f(-150 , -52));
	_score->SetOriginAtMiddle();

	scoreLabel = hud->SpawnWidget<LabelWidget>(to_string(score));
	canvasScore->AddChild(scoreLabel);
	scoreLabel->SetFillColor(Color::White);
	scoreLabel->SetFont("Score", TTF);
	scoreLabel->SetOriginAtMiddle();
	scoreLabel->SetZOrder(2);
	scoreLabel->SetCharacterSize(75);
	scoreLabel->SetPosition(Vector2f(-190, -80));

	canvasScore->SetPosition(Vector2f(_windowSize.x / 5, _windowSize.y - _windowSize.y / 20));
	hud->AddToViewport(canvasScore);
	canvasScore = hud->SpawnWidget<CanvasWidget>();

	new Timer([&]() {AddScore(5); }, seconds(1), true, true);
}

void Score::AddScore(const int _offset)
{
	score += _offset;
	scoreLabel->SetText(to_string(score));
}


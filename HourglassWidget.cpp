#include "HourglassWidget.h"
#include "Level.h"
#include "TimerManager.h"

HourglassWidget::HourglassWidget(Level* _level, HUD* _hud, const string& _name, const float _time)
	:CanvasWidget(_level, _name)
{
	chrono = new Chronometer(_time);
	label = _hud->SpawnWidget<LabelWidget>("null");
	hourglass = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(110.0f, 110.0f), "UI/Sprites/hourglass"));
	slide = _hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(170.0f, 70.0f), "UI/blue_slide"));
	AddChild(label);
	label->SetFillColor(Color::White);
	label->SetFont("Overcooked", TTF);
	label->SetCharacterSize(48);
	label->SetZOrder(9);
	label->SetPosition({ 985.0f, 485.0f });

	AddChild(hourglass);
	hourglass->SetPosition(Vector2f(1080.0f, 460.0f));
	hourglass->SetZOrder(10);

	AddChild(slide);
	slide->SetPosition(Vector2f(965.0f, 480.0f));
	slide->SetZOrder(8);

	new Timer([&]()
		{
			chrono->DecrementCurrentTime();
			label->SetText(chrono->GetTime());
			if (chrono->GetCurrentTime() < ((chrono->GetMaxTime() * 2) / 3))  label->SetFillColor(Color::Yellow);
			if (chrono->GetCurrentTime() < chrono->GetMaxTime() / 3)  label->SetFillColor(Color::Red);
		}, seconds(1), true, true);
}

HourglassWidget::HourglassWidget(const HourglassWidget& _other)
	:CanvasWidget(_other)
{

}

HourglassWidget::~HourglassWidget()
{
	delete chrono;
}

void HourglassWidget::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

}

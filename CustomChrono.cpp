#include "CustomChrono.h"

CustomChrono::CustomChrono(Level* _level, const float _time)
	:Widget(_level, "Chrono")
{
	chrono = new Chronometer(_time);
	
	InitChrono();
}

CustomChrono::~CustomChrono()
{
	delete chrono;
}

void CustomChrono::Render(RenderWindow& _window)
{
	if (visibility == Hidden) return;

}

void CustomChrono::InitChrono()
{

	AddChild(image, AT_KEEP_RELATIVE);
	image->SetOriginAtMiddle();
	image->SetPosition(Vector2f(10.0f, 0.0f));
	image->SetOriginAtMiddle();

	AddChild(image, AT_KEEP_RELATIVE);
	label->SetFillColor(Color::White);
	label->SetFont("Overcooked", TTF);
	label->SetCharacterSize(64);
	label->SetZOrder(1);

	label->SetOriginAtMiddle();
	label->SetPosition({ -10.0f, 0.0f });
	new Timer([&]() {chrono->DecrementCurrentTime(); label->SetText(chrono->GetTime()); }, seconds(1), true, true);
}

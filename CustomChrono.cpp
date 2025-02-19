#include "CustomChrono.h"

CustomChrono::CustomChrono(LabelWidget* _label, ImageWidget* _image, CanvasWidget* _canvas)
{
	chrono = new Chronometer(0, 30);
	label = _label;
	image = _image;
	canvas = _canvas;
	InitChrono();
}

CustomChrono::~CustomChrono()
{
	delete chrono;
	delete label;
	delete image;
	delete canvas;
}

void CustomChrono::InitChrono()
{
	image->SetOriginAtMiddle();
	canvas->AddChild(image);
	image->SetPosition(Vector2f(1000.0f, 500.0f));
	image->SetOriginAtMiddle();

	label->SetFillColor(Color::White);
	label->SetFont("Overcooked", TTF);
	label->SetCharacterSize(64);
	label->SetZOrder(1);
	canvas->AddChild(label);
	label->SetOriginAtMiddle();
	label->SetPosition({ 990.0f, 500.0f });
	new Timer([&]() {chrono->DecrementCurrentTime(); label->SetText(chrono->GetTime());
	if (chrono->GetCurrentTime() < ((chrono->GetMaxTime() * 2) / 3))  label->SetFillColor(Color::Yellow);
	if (chrono->GetCurrentTime() < chrono->GetMaxTime() / 3)  label->SetFillColor(Color::Red); }, seconds(1), true, true);
}

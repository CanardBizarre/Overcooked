#include "CustomChrono.h"

CustomChrono::CustomChrono(LabelWidget* _label, ImageWidget* _image, CanvasWidget* _canvas)
{
	chrono = new Chronometer(1, 30);
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
	image->SetPosition(Vector2f(10.0f, 0.0f));
	image->SetOriginAtMiddle();

	label->SetFillColor(Color::White);
	label->SetFont("Overcooked", TTF);
	label->SetCharacterSize(64);
	label->SetZOrder(1);
	canvas->AddChild(label);
	label->SetOriginAtMiddle();
	label->SetPosition({ -10.0f, 0.0f });
	new Timer([&]() {chrono->DecrementCurrentTime(); label->SetText(chrono->GetTime()); }, seconds(1), true, true);
	
	canvas->SetPosition(Vector2f(1000.0f, 500.0f));
}

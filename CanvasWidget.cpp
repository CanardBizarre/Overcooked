#include "CanvasWidget.h"

UI::CanvasWidget::CanvasWidget(Level* _level, const string& _name, const RenderType& _type) : PanelWidget(_level, _name, _type)
{
	size = { 400.0f, 300.0f };
}


void UI::CanvasWidget::Construct()
{
	Super::Construct();

	if (debugMode)
	{
		LOG(Warning, "DebugMode enabled on Canvas \"" + GetName() + "\"");
	}
}

void UI::CanvasWidget::Render(RenderWindow& _window)
{
	Super::Render(_window);
}

void UI::CanvasWidget::BindViewport()
{
	Super::BindViewport();

	for (Actor* _actor : GetChildren())
	{
		if (Widget* _widget = Cast<Widget>(_actor))
		{
			_widget->BindViewport();
		}
	}
}

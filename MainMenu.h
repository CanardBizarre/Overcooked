#pragma once
#include "Level.h"
#include "CanvasWidget.h"



class MainMenu : public Level
{

	map<string, CanvasWidget*> canvasWidgets;
public:
	MainMenu();
	virtual ~MainMenu();

public:

	virtual void Load() override;
	virtual void Unload() override;

protected:
	virtual void InitLevel() override;

private:
	CanvasWidget* InitMainMenu();

};



#include "MainMenu.h"

MainMenu::MainMenu() : Level("MainMenu")
{

}

MainMenu::~MainMenu()
{
}

void MainMenu::Load()
{
	Super::Load();
}

void MainMenu::Unload()
{
	Super::Unload();

}

void MainMenu::InitLevel()
{
}

CanvasWidget* MainMenu::InitMainMenu()
{
	return nullptr;
}

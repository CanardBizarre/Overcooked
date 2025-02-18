#include "Engine.h"
#include "LevelManager.h"
#include "TESTLevel.h"
#include "DebugLevel.h"
#include "MainMenu.h"
#include "CUSTOMLevel.h"

void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
	system("cls");
}

int main()
{
	InitConfig();

	MainMenu* _mainMenu = new MainMenu();
	M_LEVEL.SetLevel(_mainMenu);

	Engine::GetInstance().Start();

	return EXIT_SUCCESS;
}
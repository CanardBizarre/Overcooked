#include "Engine.h"
#include "LevelManager.h"
#include "TESTLevel.h"
#include "DebugLevel.h"
#include "MainMenu.h"
#include "Level_1_1.h"
#include "Level_2_1.h"
#include "Level_3_1.h"
#include "Level_4_1.h"
#include "Level_5_1.h"
#include "ChooseMapLevel.h"

void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
	system("cls");
}

int main()
{
	InitConfig();

	//MainMenu* _level = new MainMenu();
	ChooseMapLevel* _level = new ChooseMapLevel();
	M_LEVEL.SetLevel(_level);

	Engine::GetInstance().Start();

	return EXIT_SUCCESS;
}
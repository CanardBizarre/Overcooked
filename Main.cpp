#include "Engine.h"
#include "LevelManager.h"
#include "TESTLevel.h"

void InitConfig()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Logger::Reset();
	system("cls");
}

int main()
{
	InitConfig();

	TESTLevel* _level = new TESTLevel("TestLevel");
	M_LEVEL.SetLevel(_level);

	Engine::GetInstance().Start();

	return EXIT_SUCCESS;
}
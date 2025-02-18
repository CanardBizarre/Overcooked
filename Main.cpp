#include "Engine.h"
#include "LevelManager.h"
#include "DebugLevel.h"
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

	DebugLevel* _level = new DebugLevel();
	M_LEVEL.SetLevel(_level);

	Engine::GetInstance().Start();

	return EXIT_SUCCESS;
}
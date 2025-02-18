#include "Engine.h"
#include "LevelManager.h"
#include "DebugLevel.h"

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
	_level->SetGravity(9.81f);
	M_LEVEL.SetLevel(_level);

	Engine::GetInstance().Start();

	return EXIT_SUCCESS;
}
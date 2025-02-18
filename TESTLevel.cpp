#include "TESTLevel.h"
#include "FileManager.h"
#include "LevelLoader.h"
#include "MeshActor.h"

using namespace File;

TESTLevel::TESTLevel(const string& _name) : Level(_name)
{
	const string& _folders = "LevelsData/";
	path = _folders + "Level_5-1";
}

void TESTLevel::InitLevel()
{
	Super::InitLevel();

	
	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}

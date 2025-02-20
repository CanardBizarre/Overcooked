#include "MainMenuGameMode.h"
#include "LevelManager.h"
#include "MainMenu.h"

MainMenuGameMode::MainMenuGameMode(Level* _level)
	:GameMode(_level, "MainMenu")

{

}

MainMenuGameMode::MainMenuGameMode(const MainMenuGameMode& _other)
	:GameMode(_other)

{

}

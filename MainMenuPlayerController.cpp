#include "MainMenuPlayerController.h"
#include "MainMenuPawn.h"

MainMenuPlayerController::MainMenuPlayerController(Level* _level)
	: PlayerController(_level, "Main Menu")
{

}

MainMenuPlayerController::MainMenuPlayerController(const PlayerController& _other)
	: PlayerController(_other)
{

}

Pawn* MainMenuPlayerController::GetPawnRef() const
{
	return new MainMenuPawn(level);
}

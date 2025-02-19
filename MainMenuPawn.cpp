#include "MainMenuPawn.h"
#include "InputManager.h"
#include "Level.h"
#include "MainMenu.h"

using namespace Input;

MainMenuPawn::MainMenuPawn(Level* _level)
	: Pawn(_level, "MainMenuPawn")
{
}

MainMenuPawn::MainMenuPawn(const MainMenuPawn& _other)
	: Pawn(_other)
{
}

void MainMenuPawn::SetupInputController(Input::InputManager& _inputManager)
{
	ActionMap* _menuInput = _inputManager.CreateActionMap("MenuInput");

	_menuInput->AddActions(
		{
			new Action("Enter", ActionData(KeyHold, Enter), [&]()
			{
				Cast<MainMenu>(level)->ChooseScreen(ST_CHOICES);
			}),
		});
	_menuInput->Enable();
}

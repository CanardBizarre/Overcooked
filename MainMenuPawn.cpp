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
				Cast<MainMenuLevel>(level)->ChooseScreen(1);
			}),

			new Action("Backspace", ActionData(KeyHold, Backspace), [&]()
			{
				Cast<MainMenuLevel>(level)->ChooseScreen(-1);
			}),

			new Action("Up", ActionData(KeyHold, Z), [&]()
			{
				Cast<MainMenuLevel>(level)->ChooseChoices(-1);
			}),

			new Action("Down", ActionData(KeyHold, S), [&]()
			{
				Cast<MainMenuLevel>(level)->ChooseChoices(1);
			}),



		});
	_menuInput->Enable();
}

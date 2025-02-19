#pragma once
#include "Pawn.h"

class InputManager;

class MainMenuPawn: public Pawn
{
public:
	MainMenuPawn(Level* _level);
	MainMenuPawn(const MainMenuPawn& _other);

protected:
	virtual void SetupInputController(Input::InputManager& _inputManager) override;
};


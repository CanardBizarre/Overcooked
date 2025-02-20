#pragma once
#include "PlayerController.h"

class MainMenuPlayerController : public PlayerController
{
public:
	MainMenuPlayerController(Level* _level);
	MainMenuPlayerController(const PlayerController& _other);

	virtual Pawn* GetPawnRef() const override;
};


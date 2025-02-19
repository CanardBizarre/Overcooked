#pragma once
#include "GameMode.h"
#include "MainMenuPlayerController.h"
#include "MainMenuHUD.h"

class MainMenuGameMode : public GameMode
{
public:
	FORCEINLINE virtual MainMenuPlayerController* GetPlayerControllerRef() override
	{
		return new MainMenuPlayerController(GetLevel());
	}
	FORCEINLINE virtual MainMenuHUD* GetHUDRef() override
	{
		return new MainMenuHUD(GetLevel());
	}
public:
	MainMenuGameMode(Level* _level);
	MainMenuGameMode(const MainMenuGameMode& _other);
};


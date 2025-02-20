#pragma once
#include "HUD.h"

using namespace UI;

class MainMenuHUD : public HUD
{
public:
	MainMenuHUD(Level* _level);
	MainMenuHUD(const MainMenuHUD& _other);
};

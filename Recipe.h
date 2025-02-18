#pragma once
#include "HorizontalBox.h"
#include "ImageWidget.h"
#include "Level.h"
#include "TimerManager.h"
#include "Ingredient.h"
#include "ProgressBarWidget.h"

namespace CustomWidget
{
	class Recipe : public HorizontalBox
	{
		//Timer* time;
		ProgressBarWidget* progressTime;
		vector<Ingredient*> allIngredients;
		string path;
		

	public:
		Recipe();
		~Recipe();
	};
}



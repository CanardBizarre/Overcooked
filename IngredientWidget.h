#pragma once
#include "ImageWidget.h"
#include "Level.h"
#include "IngredientType.h"

class IngredientWidget
{
	UI::ImageWidget* image;
	IngredientType ingredientType;

public :
	FORCEINLINE ImageWidget* GetImage()
	{
		return image;
	}

public :
	IngredientWidget(ImageWidget* _image, IngredientType _ingredientType);
	~IngredientWidget();

private :
	void InitIngredient();
};


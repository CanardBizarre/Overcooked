#pragma once
#include "Chronometer.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "CustomWidget.h"
#include "MeshActor.h"
#include "TimerManager.h"
#include "ProgressBarWidget.h"
#include "IngredientWidget.h"

enum RecipeType
{
	RT_SALAD_LETTUCE = 0,
	RT_SALAD_LETTUCE_AND_TOMATO,
	RT_SALAD_LETTUCE_TOMATO_AND_CUCUMBER,
	RT_SUSHI_FISH,
	RT_SUSHI_FISH_AND_PRAWN,
	RT_SUSHI_CUCUMBER,
	RT_SUSHI_FISH_AND_CUCUMBER,
	RT_MUSHROOM_BURRITO,
	RT_CHICKEN_BURRITO,
	RT_BEEF_BURRITO,
	RT_BURGER,
	RT_CHOCOLATE_CAKE,
	RT_COUNT,
};

class RecipeWidget
{
	Chronometer* chrono;
	ProgressBarWidget* progressBar;
	ImageWidget* image;
	CanvasWidget* canvas;
	vector<IngredientWidget*> ingredients;
	ImageWidget* recipeSlide;
	vector<ImageWidget*> ingredientsImage;
	vector<IngredientType> ingredientsArray;
	RecipeType recipeType;

public:
	FORCEINLINE Chronometer* GetChrono()
	{
		return chrono;
	}
	FORCEINLINE ProgressBarWidget* GetProgressBar()
	{
		return progressBar;
	}
	FORCEINLINE ImageWidget* GetImage()
	{
		return image;
	}
	FORCEINLINE CanvasWidget* GetCanvas()
	{
		return canvas;
	}

public:
	RecipeWidget(ProgressBarWidget* _progressBar, ImageWidget* _image, ImageWidget* _recipeSlide, CanvasWidget* _canvas, vector<ImageWidget*> _ingredientsImage, vector<IngredientType> _ingredientsArray, RecipeType _recipeType);
	~RecipeWidget();

	void InitRecipe();
};




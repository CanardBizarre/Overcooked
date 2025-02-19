#pragma once
#include "Chronometer.h"
#include "CanvasWidget.h"
#include "ImageWidget.h"
#include "MeshActor.h"
#include "TimerManager.h"
#include "ProgressBarWidget.h"
#include "IngredientWidget.h"
#include "RecipeType.h"


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




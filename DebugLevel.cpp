#include "DebugLevel.h"
#include "ImageWidget.h"
#include "MeshActor.h"
#include "LabelWidget.h"
#include "TimerManager.h"

DebugLevel::DebugLevel() : Level("Debug")
{
	hud = GetGameMode()->GetHUD();
	chronoWidget = new CustomChrono(hud->SpawnWidget<LabelWidget>("null"),
									hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(300.0f, 150.0f), "UI/timer_slide")),
									hud->SpawnWidget<CanvasWidget>("ChronoCanvas"));
	chronoWidget->GetLabel()->SetText(chronoWidget->GetChrono()->GetTime());
	recipe.push_back(new RecipeWidget(hud->SpawnWidget<ProgressBarWidget>(PT_LEFT, RectangleShapeData(Vector2f(150.0f,10.0f),"/UI/progress_bar"), 40.0f),
								hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(50.0f, 50.0f), "/Recipes/spritesheet")),
								hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(150.0f, 150.0f), "/UI/recipe")),
								hud->SpawnWidget<CanvasWidget>("RecipeCanvas"),
								{hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(25.0f, 25.0f), "/Ingredients/spritesheet")), 
								 hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(25.0f, 25.0f), "/Ingredients/spritesheet")),
								 hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(25.0f, 25.0f), "/Ingredients/spritesheet")), },
								{ IT_TORTILLA,IT_RICE,IT_MUSHROOM}, RT_MUSHROOM_BURRITO));
	canva = hud->SpawnWidget<CanvasWidget>("GeneralCanvas");
	canva->AddChild(chronoWidget->GetCanvas());
	canva->AddChild(recipe[recipe.size() - 1]->GetCanvas());
	hud->AddToViewport(canva);
}

DebugLevel::~DebugLevel()
{
	delete chronoWidget;
	delete hud;
}

void DebugLevel::InitLevel()
{
	Super::InitLevel();
	
}

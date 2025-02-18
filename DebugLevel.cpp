#include "DebugLevel.h"
#include "CanvasWidget.h"
#include "Ingredient.h"
#include "MeshActor.h"
DebugLevel::DebugLevel() : Level("Debug")
{

}

void DebugLevel::InitLevel()
{
	Super::InitLevel();

	CustomWidget::Ingredient* _ingredient = new CustomWidget::Ingredient(this, "Ingredients/ingredients_spritesheet");

	HorizontalBox* _horizontalBox = SpawnActor<HorizontalBox>(BoxData(Vector2f(150.0f, 100.0f)));
	_horizontalBox->AddWidget(_ingredient);


	SpawnActor<MeshActor>(RectangleShapeData(GetWindowSize(), "BackGround_2", JPG), "BackGround");

	CanvasWidget* _canvas = GetGameMode()->GetHUD()->SpawnWidget<CanvasWidget>("UiGameplay");
	_canvas->AddChild(_ingredient);
	_canvas->AddChild(_horizontalBox);

	HUD* _hud = GetGameMode()->GetHUD();

	_canvas = _hud->SpawnWidget<CanvasWidget>();

	player = SpawnActor<PlayerPawn>();
	player->SetPosition(Vector2f(window.getSize()) / 2.0f);
	_ingredient->SetPosition(Vector2f(0.0f, 0.0f));

	
}

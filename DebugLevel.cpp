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

    
    CanvasWidget* _canvas = GetGameMode()->GetHUD()->SpawnWidget<CanvasWidget>("UiGameplay");
    _canvas->AddChild(_ingredient);

    
    _ingredient->SetPosition(Vector2f(100.0f, 100.0f));

    player = SpawnActor<PlayerPawn>();
    player->SetPosition(Vector2f(window.getSize()) / 2.0f);
}

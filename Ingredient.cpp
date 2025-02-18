#include "Ingredient.h"

CustomWidget::Ingredient::Ingredient(Level* _level, const string& _path, const RenderType& _type) 
	: HorizontalBox (_level, BoxData(Vector2f(50.0f, 50.0f), 5.0f))
{
	ingredientTexturePath = _path;
	ImageWidget* ingredientImage = hud->SpawnWidget<ImageWidget>(RectangleShapeData(Vector2f(50.0f, 50.0f), "Ingredients/ingredients_spritesheet", PNG));
	SetTextureRect(ingredientImage, 8);
	AddWidget(ingredientImage);
}

CustomWidget::Ingredient::~Ingredient()
{
}

void CustomWidget::Ingredient::SetTextureRect(ImageWidget* _image, const int _value)
{
	_image->SetRect(IntRect(Vector2i(_value * 125, 0), Vector2i(120, 120)));
}

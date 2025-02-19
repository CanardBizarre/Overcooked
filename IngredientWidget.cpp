#include "IngredientWidget.h"
using namespace UI;

IngredientWidget::IngredientWidget(ImageWidget* _image, IngredientType _ingredientType)
{
	image = _image;
	ingredientType = _ingredientType;
	InitIngredient();
}

IngredientWidget::~IngredientWidget()
{
	delete image;
}

void IngredientWidget::InitIngredient()
{
	image->SetRect(IntRect(Vector2i(124 * ingredientType,0),Vector2i(124,124)));
}

#include "Ingredient.h"

Ingredient::Ingredient(const IngredientType& _ingredientData, const CookingStatus _cookingData, const string& _path)
{
	ingredientData = _ingredientData;
}

Ingredient::~Ingredient()
{
}

void Ingredient::GetTextureForIngredient(IngredientType _ingredientData)
{
	texture = 
}

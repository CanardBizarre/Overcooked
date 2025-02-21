#include "Ingredient.h"

Ingredient::Ingredient(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
	 const string& _name, const IngredientType& _ingredientType, const IngredientState& _ingredientState)
	: Seizable(_level, _size, _position, _angle, ST_INGREDIENT, "Ingredients/IngredientsSpritesheet", _name)
{
	ingredientData = _ingredientType;
	ingredientState = _ingredientState;
	SetTextureRect(IntRect(Vector2i(124 * _ingredientType, 124 * _ingredientState), Vector2i(124, 124)));
}

void Ingredient::Construct()
{
	Super::Construct();
}
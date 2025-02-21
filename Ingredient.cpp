#include "Ingredient.h"

Ingredient::Ingredient(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
	 const string& _name, const IngredientType& _ingredientType, const IngredientState& _ingredientState)
	: Seizable(_level, _size, _position, _angle, ST_INGREDIENT, "Ingredients/IngredientsSpritesheet", _name)
{
	isSliced = false;
	data = _ingredientType;
	state = _ingredientState;
	SetTextureRect(IntRect(Vector2i(124 * _ingredientType, 124 * _ingredientState), Vector2i(124, 124)));
	SetZOrder(8);
}

void Ingredient::Construct()
{
	Super::Construct();

	choppingTimer = new Timer([&]() { FinishChopping(); }, seconds(3), false, true);
	boilingTimer = new Timer([&]() { FinishBoiling(); }, seconds(3), false, true);

	choppingTimer->Reset();
	boilingTimer->Reset();
}

void Ingredient::FinishChopping()
{
	SetState(IS_CUT);
	isSliced = true;
	choppingTimer->Pause();

}

void Ingredient::FinishBoiling()
{
	state == IS_COOKED ? SetState(IS_BURNT) : SetState(IS_COOKED);

}

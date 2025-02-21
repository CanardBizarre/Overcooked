#pragma once
#include "Seizable.h"

enum IngredientType
{
	IT_TORTILLA = 0,
	IT_CHICKEN,
	IT_CUCUMBER,
	IT_FISH,
	IT_LETTUCE,
	IT_MEAT,
	IT_MUSHROOM,
	IT_PRAWN,
	IT_RICE,
	IT_SEAWEED,
	IT_TOMATO,
	IT_COUNT
};

enum IngredientState
{
	IS_RAW = 0,
	IS_CUT,
	IS_COOKED,
	IS_BURNT
};

class Ingredient : public Seizable
{
	IngredientType ingredientData;
	IngredientState ingredientState;
	bool isSlinced;


public:
	Ingredient() = default;
	Ingredient(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _name,
				const IngredientType& _ingredientData, const IngredientState& _ingredientState = IS_RAW);

public:
	virtual void Construct() override;

};


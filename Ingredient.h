#pragma once
#include "Seizable.h"
#include "IngredientType.h"

struct TextureRegion
{
	Vector2i position;
	Vector2i size;
};

class Ingredient : public Seizable
{
	IngredientType ingredientData;
	IngredientState ingredientState;
	bool isSlinced;
	TextureRegion texture;


public:
	Ingredient() = default;
	Ingredient(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _name,
		const IngredientType& _ingredientData, const IngredientState& _ingredientState = IS_RAW);

public:
	virtual void Construct() override;


public:

	map<IngredientType, TextureRegion> InitTextureUVMap(const IngredientType& _ingredientData);
};
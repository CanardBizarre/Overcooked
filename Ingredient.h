#pragma once
#include "Seizable.h"

//enum IngredientType
//{
//	IT_APPLE,
//	IT_BACON,
//	IT_BANANA,
//	IT_BEANS,
//	IT_BEEFJOINT,
//	IT_BLACKBERRY,
//	IT_BLUEBERRY,
//	IT_BOKCHOY,
//	IT_BROCOLI,
//	IT_BUN,
//	IT_CARROT,
//	IT_CHEESE,
//	IT_CHERY,
//	IT_CHICKEN,
//	IT_CHOCOLATE,
//	IT_CRACKER,
//	IT_CUCUMBER,
//	IT_DOUGH,
//	IT_DRIEDFRUITS,
//	IT_DRINk,
//	IT_EGG,
//	IT_FISH,
//	IT_FLOUR,
//	IT_GRAPE,
//	IT_HONEY,
//	IT_HOTDOGBUN,
//	IT_HOTWATER,
//	IT_KETCHUP,
//	IT_LEEK,
//	IT_LETTUCE,
//	IT_MARSHMALLOW,
//	IT_MEAT,
//	IT_MELON,
//	IT_MILK,
//	IT_MUSHROOM,
//	IT_MUSTARD,
//	IT_NOODLE,
//	IT_OLIVE,
//	IT_ONION,
//	IT_ORANGE,
//	IT_PASTA,
//	IT_PEACH,
//	IT_PEPPERONI,
//	IT_PINEAPPLE,
//	IT_POTATO,
//	IT_PRAWN,
//	IT_EASBERRY,
//	IT_RICE,
//	IT_SAUSAGE,
//	IT_SEAWEED,
//	IT_SPICES,
//	IT_STRPINGONION,
//	IT_STRAWBERRY,
//	IT_TEA,
//	IT_TOTMATO,
//	IT_TORTILLA,
//	IT_WHIPPEDCREAM,
//
//	IT_COUNT
//
//};

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
	Ingredient(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _path, const string& _name,
				const IngredientType& _ingredientData, const IngredientState& _ingredientState = IS_RAW);
	~Ingredient();

public:
	void Draw(RenderWindow& window);
	virtual void Construct() override;


public: 

	map<IngredientType, TextureRegion> InitTextureUVMap(const IngredientType& _ingredientData);
};


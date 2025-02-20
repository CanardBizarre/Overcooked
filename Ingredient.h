#pragma once
#include "Sizeable.h"


enum IngredientType
{
	IT_APPLE,
	IT_BACON,
	IT_BANANA,
	IT_BEANS,
	IT_BEEFJOINT,
	IT_BLACKBERRY,
	IT_BLUEBERRY,
	IT_BOKCHOY,
	IT_BROCOLI,
	IT_BUN,
	IT_CARROT,
	IT_CHEESE,
	IT_CHERY,
	IT_CHICKEN,
	IT_CHOCOLATE,
	IT_CRACKER,
	IT_CUCUMBER,
	IT_DOUGH,
	IT_DRIEDFRUITS,
	IT_DRINk,
	IT_EGG,
	IT_FISH,
	IT_FLOUR,
	IT_GRAPE,
	IT_HONEY,
	IT_HOTDOGBUN,
	IT_HOTWATER,
	IT_KETCHUP,
	IT_LEEK,
	IT_LETTUCE,
	IT_MARSHMALLOW,
	IT_MEAT,
	IT_MELON,
	IT_MILK,
	IT_MUSHROOM,
	IT_MUSTARD,
	IT_NOODLE,
	IT_OLIVE,
	IT_ONION,
	IT_ORANGE,
	IT_PASTA,
	IT_PEACH,
	IT_PEPPERONI,
	IT_PINEAPPLE,
	IT_POTATO,
	IT_PRAWN,
	IT_EASBERRY,
	IT_RICE,
	IT_SAUSAGE,
	IT_SEAWEED,
	IT_SPICES,
	IT_STRPINGONION,
	IT_STRAWBERRY,
	IT_TEA,
	IT_TOTMATO,
	IT_TORTILLA,
	IT_WHIPPEDCREAM,

	IT_COUNT

};

enum CookingStatus
{
	CS_FRESH,
	CS_COOKED,
	CS_BURNED,

	CS_COUNT
};

struct TextureRegion
{
	Vector2f position;
	Vector2f size;
};

class Ingredient : public Sizeable
{
	IngredientType ingredientData;
	CookingStatus cookingData;
	bool isSlinced;
	TextureRegion texture;


public:
	Ingredient(const IngredientType& _ingredientData, const CookingStatus _cookingData = CS_FRESH, const string& _path = "default");
	~Ingredient();

private: 
	void GetTextureForIngredient(IngredientType _ingredientData);

	map<IngredientType, TextureRegion> initTextureUVMap() 

	{
		std::map<IngredientType, TextureRegion> _ingedientMap;

		_ingedientMap[IT_APPLE] = { sf::Vector2f(0.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BACON] = { sf::Vector2f(125.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BANANA] = { sf::Vector2f(300.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BEANS] = { sf::Vector2f(450.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BEEFJOINT] = { sf::Vector2f(600.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BLACKBERRY] = { sf::Vector2f(750.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BLUEBERRY] = { sf::Vector2f(900.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BOKCHOY] = { sf::Vector2f(1050.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BROCOLI] = { sf::Vector2f(1200.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_BUN] = { sf::Vector2f(1350.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_CARROT] = { sf::Vector2f(1500.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_CHEESE] = { sf::Vector2f(1650.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_CHERY] = { sf::Vector2f(1800.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_CHICKEN] = { sf::Vector2f(1950.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_CHOCOLATE] = { sf::Vector2f(2100.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_CRACKER] = { sf::Vector2f(2250.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_CUCUMBER] = { sf::Vector2f(2400.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_DOUGH] = { sf::Vector2f(25500.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_DRIEDFRUITS] = { sf::Vector2f(2700.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_DRINk] = { sf::Vector2f(2850.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_EGG] = { sf::Vector2f(3000.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_FISH] = { sf::Vector2f(3150.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_FLOUR] = { sf::Vector2f(3300.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_GRAPE] = { sf::Vector2f(3450.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_HONEY] = { sf::Vector2f(3600.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_HOTDOGBUN] = { sf::Vector2f(3750.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_HOTWATER] = { sf::Vector2f(3900.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_KETCHUP] = { sf::Vector2f(4050.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_LEEK] = { sf::Vector2f(4200.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_LETTUCE] = { sf::Vector2f(4350.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_MARSHMALLOW] = { sf::Vector2f(4500.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_MEAT] = { sf::Vector2f(4650.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_MELON] = { sf::Vector2f(4800.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_MILK] = { sf::Vector2f(4950.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_MUSHROOM] = { sf::Vector2f(5100.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_MUSTARD] = { sf::Vector2f(5250.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_NOODLE] = { sf::Vector2f(5400.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_OLIVE] = { sf::Vector2f(5550.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_ONION] = { sf::Vector2f(5700.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_ORANGE] = { sf::Vector2f(5850.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_PASTA] = { sf::Vector2f(6000.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_PEACH] = { sf::Vector2f(6150.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_PEPPERONI] = { sf::Vector2f(6300.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_PINEAPPLE] = { sf::Vector2f(6450.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_POTATO] = { sf::Vector2f(6600.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_PRAWN] = { sf::Vector2f(6750.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_EASBERRY] = { sf::Vector2f(6900.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_RICE] = { sf::Vector2f(7050.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_SAUSAGE] = { sf::Vector2f(7200.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_SEAWEED] = { sf::Vector2f(7350.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_SPICES] = { sf::Vector2f(7500.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_STRPINGONION] = { sf::Vector2f(7650.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_STRAWBERRY] = { sf::Vector2f(7800.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_TEA] = { sf::Vector2f(7950.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_TOTMATO] = { sf::Vector2f(8100.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_TORTILLA] = { sf::Vector2f(8250.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		_ingedientMap[IT_WHIPPEDCREAM] = { sf::Vector2f(8400.0f, 0.0f), sf::Vector2f(125.0f, 125.0f) };
		

		return _ingedientMap;
	}
};


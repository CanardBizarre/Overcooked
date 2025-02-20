#include "Ingredient.h"

Ingredient::Ingredient(const IngredientType& _ingredientData, const CookingStatus _cookingData, const string& _path)
{
	ingredientData = _ingredientData;
}

Ingredient::~Ingredient()
{
}

void Ingredient::Draw(RenderWindow& window)
{

	
	static Texture texture;
	if (!texture.loadFromFile("Ingredients/ingredients_spritesheet.png")) {
		
		std::cerr << "Erreur de chargement de la texture !" << std::endl;
		return;
	}


	Sprite sprite(texture);

	
	auto textureRegion = initTextureUVMap(ingredientData);


	auto region = textureRegion[ingredientData];

	
	sprite.setTextureRect(IntRect(
		region.position,
		region.size	
	));

	
	sprite.setPosition(Vector2f(600.0f, 800.0f));

	
	window.draw(sprite);
}

map<IngredientType, TextureRegion> Ingredient::initTextureUVMap(const IngredientType& _ingredientData)

{
	std::map<IngredientType, TextureRegion> _ingedientMap;

	_ingedientMap[IT_APPLE] = { sf::Vector2i(0, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BACON] = { sf::Vector2i(125, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BANANA] = { sf::Vector2i(300, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BEANS] = { sf::Vector2i(450, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BEEFJOINT] = { sf::Vector2i(600, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BLACKBERRY] = { sf::Vector2i(750, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BLUEBERRY] = { sf::Vector2i(900, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BOKCHOY] = { sf::Vector2i(1050, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BROCOLI] = { sf::Vector2i(1200, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_BUN] = { sf::Vector2i(1350, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CARROT] = { sf::Vector2i(1500, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CHEESE] = { sf::Vector2i(1650, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CHERY] = { sf::Vector2i(1800, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CHICKEN] = { sf::Vector2i(1950, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CHOCOLATE] = { sf::Vector2i(2100, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CRACKER] = { sf::Vector2i(2250, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CUCUMBER] = { sf::Vector2i(2400, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_DOUGH] = { sf::Vector2i(25500, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_DRIEDFRUITS] = { sf::Vector2i(2700, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_DRINk] = { sf::Vector2i(2850, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_EGG] = { sf::Vector2i(3000, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_FISH] = { sf::Vector2i(3150, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_FLOUR] = { sf::Vector2i(3300, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_GRAPE] = { sf::Vector2i(3450, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_HONEY] = { sf::Vector2i(3600, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_HOTDOGBUN] = { sf::Vector2i(3750, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_HOTWATER] = { sf::Vector2i(3900, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_KETCHUP] = { sf::Vector2i(4050, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_LEEK] = { sf::Vector2i(4200, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_LETTUCE] = { sf::Vector2i(4350, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MARSHMALLOW] = { sf::Vector2i(4500, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MEAT] = { sf::Vector2i(4650, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MELON] = { sf::Vector2i(4800, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MILK] = { sf::Vector2i(4950, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MUSHROOM] = { sf::Vector2i(5100, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MUSTARD] = { sf::Vector2i(5250, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_NOODLE] = { sf::Vector2i(5400, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_OLIVE] = { sf::Vector2i(5550, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_ONION] = { sf::Vector2i(5700, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_ORANGE] = { sf::Vector2i(5850, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_PASTA] = { sf::Vector2i(6000, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_PEACH] = { sf::Vector2i(6150, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_PEPPERONI] = { sf::Vector2i(6300, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_PINEAPPLE] = { sf::Vector2i(6450, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_POTATO] = { sf::Vector2i(6600, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_PRAWN] = { sf::Vector2i(6750, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_EASBERRY] = { sf::Vector2i(6900, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_RICE] = { sf::Vector2i(7050, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_SAUSAGE] = { sf::Vector2i(7200, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_SEAWEED] = { sf::Vector2i(7350, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_SPICES] = { sf::Vector2i(7500, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_STRPINGONION] = { sf::Vector2i(7650, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_STRAWBERRY] = { sf::Vector2i(7800, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_TEA] = { sf::Vector2i(7950, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_TOTMATO] = { sf::Vector2i(8100, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_TORTILLA] = { sf::Vector2i(8250, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_WHIPPEDCREAM] = { sf::Vector2i(8400, 0), sf::Vector2i(125, 125) };


	return _ingedientMap;
}

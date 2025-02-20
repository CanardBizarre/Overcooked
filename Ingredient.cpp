#include "Ingredient.h"

Ingredient::Ingredient(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
	const string& _path, const string& _name, const IngredientType& _ingredientType, const IngredientState& _ingredientState)
	: Seizable(_level, _size, _position, _angle, ST_INGREDIENT, _path, _name)
{
	ingredientData = _ingredientType;
	ingredientState = _ingredientState;
	SetTextureRect(IntRect(Vector2i(124 * _ingredientType, 124 * _ingredientState), Vector2i(124, 124)));
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

	
	auto textureRegion = InitTextureUVMap(ingredientData);


	auto region = textureRegion[ingredientData];

	
	sprite.setTextureRect(IntRect(
		region.position,
		region.size	
	));

	
	sprite.setPosition(Vector2f(600.0f, 800.0f));

}

void Ingredient::Construct()
{
	Super::Construct();
}

map<IngredientType, TextureRegion> Ingredient::InitTextureUVMap(const IngredientType& _ingredientData)

{
	std::map<IngredientType, TextureRegion> _ingedientMap;

	_ingedientMap[IT_TORTILLA] = { sf::Vector2i(0, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CHICKEN] = { sf::Vector2i(124, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_CUCUMBER] = { sf::Vector2i(248, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_FISH] = { sf::Vector2i(372, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_LETTUCE] = { sf::Vector2i(496, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MEAT] = { sf::Vector2i(620, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_MUSHROOM] = { sf::Vector2i(744, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_PRAWN] = { sf::Vector2i(868, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_RICE] = { sf::Vector2i(992, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_SEAWEED] = { sf::Vector2i(1116, 0), sf::Vector2i(125, 125) };
	_ingedientMap[IT_TOMATO] = { sf::Vector2i(1240, 0), sf::Vector2i(125, 125) };


	return _ingedientMap;
}

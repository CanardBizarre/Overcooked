#include "FoodSpawner.h"
#include "Level.h"

FoodSpawner::FoodSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
	const BlockType& _type, const string& _name) : KitchenBlock(_level, _size, _position, _angle, _type, _name)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_FOOD_SPAWNER, 0), Vector2i(124, 124)));
	icon = nullptr;
}

FoodSpawner::FoodSpawner(const FoodSpawner& _other) : KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_FOOD_SPAWNER, 0), Vector2i(124, 124)));
	icon = _other.icon;
}

Ingredient* FoodSpawner::SpawnIngredient(const IngredientType type, const IngredientState status, const string& _name)
{
	return level->SpawnActor<Ingredient>(Vector2f(40.0f, 40.0f), GetPosition(), Angle(), "/Ingredients/spritesheet", _name, type, status);
}

void FoodSpawner::Construct()
{
	Super::Construct();

	icon = level->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(35.0f, 35.0f), "/Ingredients/spritesheet", PNG, false, IntRect(Vector2i(124 * type, 0), Vector2i(124, 124))));
	icon->GetMesh()->SetOriginAtMiddle();
	icon->SetPosition(GetPosition());
	AddChild(icon, AT_SNAP_TO_TARGET);
}

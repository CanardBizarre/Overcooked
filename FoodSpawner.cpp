#include "FoodSpawner.h"
#include "Level.h"

FoodSpawner::FoodSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle,
	const string& _name) : KitchenBlock(_level, _size, _position, _angle, BT_FOOD_SPAWNER, _name)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_FOOD_SPAWNER, 0), Vector2i(124, 124)));

	type = IT_COUNT;
	icon = nullptr;
}

FoodSpawner::FoodSpawner(const FoodSpawner& _other) : KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_FOOD_SPAWNER, 0), Vector2i(124, 124)));

	type = IT_COUNT;
	icon = _other.icon;
}

Ingredient* FoodSpawner::SpawnIngredient(const IngredientType type, const string& _name)
{
	return level->SpawnActor<Ingredient>(Vector2f(30.0f, 30.0f), GetPosition(), Angle(), _name, type, IS_RAW);
}

void FoodSpawner::Construct()
{
	Super::Construct();
}

void FoodSpawner::InitIcon()
{
	if (!icon)
	{
		icon = GetLevel()->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(35.0f, 35.0f), "Ingredients/IngredientsSpritesheet", PNG, false, IntRect(Vector2i(124 * type, 0), Vector2i(124, 124))));
		AddChild(icon, AT_SNAP_TO_TARGET);
	}

	icon->GetMesh()->SetOriginAtMiddle();
	icon->SetPosition(GetPosition());
}

bool FoodSpawner::ActionWithoutObject(HandSocket* _hand)
{
	if (type == IT_COUNT) return false;

	_hand->AddChild(SpawnIngredient(type, "Ingredient"), AT_SNAP_TO_TARGET);

	return true;
}
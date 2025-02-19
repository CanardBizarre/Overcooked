#include "FoodSpawner.h"

FoodSpawner::FoodSpawner(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_FOOD_SPAWNER, "Food_Spawner")
{
	SetTextureRect(IntRect(Vector2i(124 * BT_FOOD_SPAWNER, 0), Vector2i(124, 124)));
}

FoodSpawner::FoodSpawner(const FoodSpawner& _other)
	: KitchenBlock(_other)
{
	SetTextureRect(IntRect(Vector2i(124 * BT_FOOD_SPAWNER, 0), Vector2i(124, 124)));
}

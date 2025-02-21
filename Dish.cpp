#include "Dish.h"

Dish::Dish(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, 
	const string& _name)
	: Seizable(_level, _size, _position, _angle, ST_DISH, "Props/PropsSpritesheet", _name)
{
	ingredients = set<Ingredient*>();
	SetTextureRect(IntRect(Vector2i(0, 0), Vector2i(124, 124)));
	SetZOrder(35.0f);
}

void Dish::SetZOrder(const int _zOrder)
{
	Super::SetZOrder(_zOrder);

	GetLevel()->GetCameraManager().SetZOrder(mesh->GetRenderMeshToken(), zOrder);
}
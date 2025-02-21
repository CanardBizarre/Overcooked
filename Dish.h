#pragma once

#include "Seizable.h"
#include "Ingredient.h"

class Dish : public Seizable
{

	set<Ingredient*> ingredients;
public:
	FORCEINLINE set<Ingredient*> GetIngredients() const
	{
		return ingredients;
	}
	FORCEINLINE void AddIngredient(Ingredient* _ingredient)
	{
		ingredients.insert(_ingredient);
		AddChild(_ingredient, AT_SNAP_TO_TARGET);
		_ingredient->SetPosition(GetPosition());
	}
	FORCEINLINE void RemoveIngredient(Ingredient* _ingredient)
	{
		ingredients.erase(_ingredient);
		RemoveChild(_ingredient);
		_ingredient->SetToDelete();
	}
public:
	Dish(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _name = "Dish");

	virtual void SetZOrder(const int _zOrder) override;

};


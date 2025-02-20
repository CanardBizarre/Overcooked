#pragma once
#include "Level.h"
#include "PlayerPawn.h"
#include "CanvasWidget.h"
#include "OrderWidget.h"
#include "HorizontalBox.h"

using namespace Camera;

class GameplayLevel : public Level
{
	HUD* hud;
	CanvasWidget* canvas; 
	HorizontalBox* orders;
	vector<OrderWidget*> _order;
	PlayerPawn* player1;
	PlayerPawn* player2;
	float gravity;
public:
	FORCEINLINE float GetGravity() const
	{
		return gravity;
	}
	FORCEINLINE void SetGravity(const float _gravity)
	{
		gravity = _gravity;
	}
public:
	GameplayLevel(const string& _name);


protected:
	virtual void InitLevel() override;
	virtual void MakeOrderWidget(const DishType& _dish, const vector<IngredientType>& _ingredients);
};


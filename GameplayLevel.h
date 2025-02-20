#pragma once
#include "Level.h"
#include "PlayerPawn.h"
#include "CanvasWidget.h"
#include "OrderWidget.h"
#include "HorizontalBox.h"
#include "FoodSpawner.h"

using namespace Camera;

class GameplayLevel : public Level
{
	HUD* hud;
	CanvasWidget* canvas; 
	unordered_set<OrderWidget*> orders;

	PlayerPawn* player1;
	PlayerPawn* player2;
	float gravity;

protected:
	vector<FoodSpawner*> foodSpawners;

public:
	FORCEINLINE void AddFoodSpawner(FoodSpawner* _foodSpawner)
	{
		foodSpawners.push_back(_foodSpawner);
	}
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

private:
	void ComputeOrdersPos();
protected:
	virtual void InitLevel() override;
	virtual void MakeOrderWidget(const DishType& _dish, const vector<IngredientType>& _ingredients);
};


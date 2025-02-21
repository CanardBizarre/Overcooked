#pragma once
#include "Level.h"
#include "PlayerPawn.h"
#include "CanvasWidget.h"
#include "ScoreWidget.h"
#include "OrderWidget.h"
#include "HorizontalBox.h"
#include "FoodSpawner.h"
#include "HourglassWidget.h"

using namespace Camera;

class GameplayLevel : public Level
{
	float gravity;

	HUD* hud;
	CanvasWidget* canvas;
	HourglassWidget* hourglass;
	ScoreWidget* score;
	PlayerPawn* player1;
	PlayerPawn* player2;

protected:
	unordered_set<OrderWidget*> orders;
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
	void InitEnd();
protected:
	virtual void InitLevel() override;
	virtual void MakeOrderWidget(const DishType& _dish, const vector<IngredientType>& _ingredients);
};
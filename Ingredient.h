#pragma once
#include "Seizable.h"
#include "TimerManager.h"

enum IngredientType
{
	IT_TORTILLA = 0,
	IT_CHICKEN,
	IT_CUCUMBER,
	IT_FISH,
	IT_LETTUCE,
	IT_MEAT,
	IT_MUSHROOM,
	IT_PRAWN,
	IT_RICE,
	IT_SEAWEED,
	IT_TOMATO,
	IT_COUNT
};

enum IngredientState
{
	IS_RAW = 0,
	IS_CUT,
	IS_COOKED,
	IS_BURNT
};

class Ingredient : public Seizable
{
	bool isSliced;
	IngredientType data;
	IngredientState state;
	Timer<Seconds>* choppingTimer;
	Timer<Seconds>* boilingTimer;

public:
	FORCEINLINE bool IsSliced() const
	{
		return isSliced;
	}
	FORCEINLINE void SetState(const IngredientState& _state)
	{
		state = _state;
		SetTextureRect(IntRect(Vector2i(124 * data, 124 * state), Vector2i(124, 124)));
	}
	FORCEINLINE Timer<Seconds>* GetChoppingTimer() const
	{
		return choppingTimer;
	}
	FORCEINLINE Timer<Seconds>* GetBoilingTimer() const
	{
		return boilingTimer;
	}
public:
	Ingredient() = default;
	Ingredient(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const string& _name,
				const IngredientType& _ingredientData, const IngredientState& _ingredientState = IS_RAW);

public:
	virtual void Construct() override;
	
	void FinishChopping();
	void FinishBoiling();

};


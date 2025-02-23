#pragma once
#include "Seizable.h"
#include "IngredientType.h"
#include "TimerManager.h"

struct TextureRegion
{
	Vector2i position;
	Vector2i size;
};

class Ingredient : public Seizable
{
	IngredientType ingredientData;
	IngredientState ingredientState;
	bool isSlinced;
	TextureRegion texture;
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

	virtual void SetZOrder(const int _zOrder) override;
public:
	map<IngredientType, TextureRegion> InitTextureUVMap(const IngredientType& _ingredientData);
};
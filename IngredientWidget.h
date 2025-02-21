#pragma once
#include "ImageWidget.h"
#include "IngredientType.h"

using namespace UI;
class IngredientWidget : public ImageWidget
{
	float sizeF;
	IngredientType type;
	IngredientState state;
	bool isCookable;

public:
	FORCEINLINE float GetSizeF()
	{
		return sizeF;
	}
	FORCEINLINE void IsRaw()
	{
		state = IS_RAW;
	}
	FORCEINLINE void IsCut()
	{
		state = IS_CUT;
	}
	FORCEINLINE void IsCooked()
	{
		state = IS_COOKED;
	}
	FORCEINLINE void IsBurnt()
	{
		state = IS_BURNT;
	}

public:
	IngredientWidget(Level* _level, const IngredientType& _type, const float _size = 30.0f);
	IngredientWidget(const IngredientWidget& _other);

public:
	void Reuse(const IngredientType& _type);

private:
	void InitState();
};


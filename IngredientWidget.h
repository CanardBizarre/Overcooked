#pragma once
#include "ImageWidget.h"
#include "IngredientType.h"

using namespace UI;
class IngredientWidget : public ImageWidget
{
	IngredientType type;
	IngredientState state;

public:
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
	IngredientWidget(Level* _level, const IngredientType& _type);
	IngredientWidget(const IngredientWidget& _other);
};


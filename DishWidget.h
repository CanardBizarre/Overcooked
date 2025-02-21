#pragma once
#include "ImageWidget.h"
#include "DishType.h"

using namespace UI;
class DishWidget : public ImageWidget
{
	float sizeF;
	DishType type;
public:
	FORCEINLINE float GetSizeF()
	{
		return sizeF;
	}
public:
	DishWidget(Level* _level, const DishType& _type, const float _size = 80.0f);
	DishWidget(const DishWidget& _other);

public:
	void Reuse(const DishType& _type);
};


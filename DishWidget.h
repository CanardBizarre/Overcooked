#pragma once
#include "ImageWidget.h"
#include "DishType.h"

using namespace UI;
class DishWidget : public ImageWidget
{
	DishType type;

public:
	DishWidget(Level* _level, const DishType& _type);
	DishWidget(const DishWidget& _other);
};


#pragma once

#include "KitchenBlock.h"

class Sink : public KitchenBlock
{
public:
	Sink(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Sink(const Sink& _other);

	virtual void Tick(const float _deltaTime) override
	{
		Super::Tick(_deltaTime);
	}
};


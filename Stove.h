#pragma once

#include "KitchenBlock.h"
#include "TimerManager.h"

class Stove : public KitchenBlock
{

public:
	Stove(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	Stove(const Stove& _other);

public:
	virtual bool EnterAction(Actor* _object, const bool _isDish) override;
	virtual bool ExitAction(Actor* _object) override;
	virtual void Construct() override;
};


#pragma once

#include "KitchenBlock.h"
#include "TimerManager.h"

class ChoppingStation : public KitchenBlock
{
public:
	ChoppingStation(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle = Angle());
	ChoppingStation(const ChoppingStation& _other);

public:
	virtual bool EnterAction(Actor* _object, const bool _isDish) override;
	virtual bool ExitAction(Actor* _object) override;
	virtual void Construct() override;
};


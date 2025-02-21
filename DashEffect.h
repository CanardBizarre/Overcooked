#pragma once
#include "MeshActor.h"
#include "Prop.h"
#include "AnimationComponent.h"

class DashEffect : public Prop
{
	AnimationComponent* dash;

public:

	DashEffect(Level* _level, const RectangleShapeData& _data, const string& _name);
	DashEffect(const DashEffect& _other);

	void DashAnimation();

};


#pragma once
#include "MeshActor.h"

class Prop : public MeshActor
{

	Prop(Level* _level, const RectangleShapeData& _data, const string& _name = "Prop");
	Prop(const Prop& _other);
};


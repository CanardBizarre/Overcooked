#pragma once
#include "MeshActor.h"

class Prop : public MeshActor
{
public:
	Prop(Level* _level, const RectangleShapeData& _data, const string& _name = "Prop");
	Prop(const Prop& _other);
};


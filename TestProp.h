#pragma once
#include "RigidProp.h"

class TestProp : public RigidProp
{
public:
	TestProp(Level* _level, const RectangleShapeData& _data, const string& _name = "TestProp");
	TestProp(const TestProp& _other);
};


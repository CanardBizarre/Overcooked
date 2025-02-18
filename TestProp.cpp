#include "TestProp.h"

TestProp::TestProp(Level* _level, const RectangleShapeData& _data, const string& _name) : RigidProp(_level, _data, _name)
{
	GetMovement()->SetSpeed(100.0f);
	GetMovement()->SetDirection({ 1.0f,0.0f });
}

TestProp::TestProp(const TestProp& _other) : RigidProp(_other)
{
	GetMovement()->SetSpeed(100.0f);
	GetMovement()->SetDirection({ 1.0f,0.0f });
}

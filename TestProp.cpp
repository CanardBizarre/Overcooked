#include "TestProp.h"

TestProp::TestProp(Level* _level, const RectangleShapeData& _data, const string& _name) : RigidProp(_level, _data, _name)
{
	GetMovement()->SetVelocity({10.0f, 10.0f});
	GetMovement()->SetDirection({ 1.0f,0.0f });
}

TestProp::TestProp(const TestProp& _other) : RigidProp(_other)
{
	GetMovement()->SetVelocity({ 10.0f, 10.0f });
	GetMovement()->SetDirection({ 1.0f,0.0f });
}

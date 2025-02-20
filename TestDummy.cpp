#include "TestDummy.h"

TestDummy::TestDummy(Level* _level)
	:RigidActor(_level, RectangleShapeData(Vector2f(20.0f,20.0f), "Ball", PNG))
{
	InitCollision();
}

TestDummy::TestDummy(const TestDummy& _other)
	:RigidActor(_other)
{
}

void TestDummy::InitCollision()
{
	GetCollision()->SetInformation("Test", IS_ALL, CT_OVERLAP);
	vector<pair<string, CollisionType>> _reponses
	{
		{"Hand", CT_OVERLAP},
		//{"NONE", CT_NONE},
	};
	GetCollision()->AddResponses(_reponses);
	SetLayerType(PROP);
}

void TestDummy::Throw(const Vector2f& _direction)
{
	move->SetDirection(_direction);
}

void TestDummy::CollisionEnter(const CollisionData& _data)
{
}

void TestDummy::CollisionUpdate(const CollisionData& _data)
{
}

void TestDummy::CollisionExit(const CollisionData& _data)
{
}

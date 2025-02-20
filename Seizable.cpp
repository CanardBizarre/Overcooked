#include "Seizable.h"

Seizable::Seizable(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle,
	const SeizableType& _type, const string& _path, const string& _name)
	: RigidProp(_level, RectangleShapeData(_size, _path, PNG), _name)
{

}

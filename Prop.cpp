#include "Prop.h"

Prop::Prop(Level* _level, const RectangleShapeData& _data, const string& _name) : MeshActor(_level, _data, _name)
{
}

Prop::Prop(const Prop& _other) : MeshActor(_other)
{
}

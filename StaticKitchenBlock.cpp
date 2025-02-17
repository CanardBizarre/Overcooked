#include "StaticKitchenBlock.h"

StaticKitchenBlock::StaticKitchenBlock(Level* _level, const Vector2f& _position, const Angle& _angle, const BlockType& _type
									 , const RectangleShapeData& _data, const string& _name)
									 : KitchenBlock(_level, _position, _angle, _type, _data, _name)
{

}

StaticKitchenBlock::StaticKitchenBlock(const StaticKitchenBlock& _other) : KitchenBlock(_other)
{

}

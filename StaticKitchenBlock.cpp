#include "StaticKitchenBlock.h"

StaticKitchenBlock::StaticKitchenBlock(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle
									 , const BlockType& _type, const string& _name)
									 : KitchenBlock(_level, _size, _position, _angle, _type, _name)
{

}

StaticKitchenBlock::StaticKitchenBlock(const StaticKitchenBlock& _other) : KitchenBlock(_other)
{

}

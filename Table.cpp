#include "Table.h"

Table::Table(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle)
	: KitchenBlock(_level, _size, _position, _angle, BT_TABLE, "Work_Plan", "/Blocks/Table")
{
}

Table::Table(const Table& _other) : KitchenBlock(_other)
{
}

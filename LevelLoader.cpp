#include "LevelLoader.h"
#include "MeshComponent.h"
#include "LevelManager.h"
#include "Utilities.h"
#include "MeshActor.h"
#include "WorkPlan.h"
#include "ChoppingStation.h"
#include "GarbageCan.h"
#include "Sink.h"
#include "Stove.h"
#include "PlateSpawner.h"
#include "FoodSpawner.h"
#include "Conveyor.h"

LevelLoader::LevelLoader()
{

}

void LevelLoader::InterpretString(const vector<string>& _info)
{
	float _angle;
	string _type;
	Vector2f _pos;
	Vector2f _size;
	Vector2f _defaultSize = Vector2f(50.0f, 50.0f);
	Vector2u _count = Vector2u(1, 1);

	Level* _level = M_LEVEL.GetCurrentLevel();

	for (u_int _index = 0; _index < _info.size(); _index++)
	{
		stringstream _stream = stringstream(_info[_index]);

		if (HasFoundSymbolInLine(_info[_index], '#'))
		{
			GetStringUntilChar(_stream, '#');
			_count.x = stof(GetStringUntilChar(_stream, '|'));
			_count.y = stof(GetStringUntilChar(_stream, '|'));
		}

		_pos.x = stof(GetStringUntilChar(_stream, '|'));
		_pos.y = stof(GetStringUntilChar(_stream, '|'));

		_size.x = stof(GetStringUntilChar(_stream, '|'));
		_size.y = stof(GetStringUntilChar(_stream, '|'));

		_angle = stof(GetStringUntilChar(_stream, '|'));

		_type = GetStringUntilChar(_stream, '|');

		for (u_int _rowIndex = 0; _rowIndex < _count.x; _rowIndex++)
		{
			for (u_int _colIndex = 0; _colIndex < _count.y; _colIndex++)
			{
				const Vector2f& _finalPos = Vector2f(_pos.x * _defaultSize.x + _rowIndex * _defaultSize.x,
													 _pos.y * _defaultSize.y + _colIndex * _defaultSize.y);

				SpawnBlockByType(_level, _size, _finalPos, Angle(degrees(_angle)), GetBlockTypeByText(_type));
			}
		}
		_count = Vector2u(1, 1);
	}
}

void LevelLoader::SpawnBlockByType(Level* _level, const Vector2f& _size, const Vector2f& _position, const Angle& _angle, const BlockType& _type)
{
	switch (_type)
	{
	case BT_WORK_PLAN:
		_level->SpawnActor<WorkPlan>(_size, _position, _angle);
		break;
	case BT_GARBAGE_CAN:
		_level->SpawnActor<GarbageCan>(_size, _position, _angle);
		break;
	case BT_CHOPPING_STATION:
		_level->SpawnActor<ChoppingStation>(_size, _position, _angle);
		break;
	case BT_STOVE:
		_level->SpawnActor<Stove>(_size, _position, _angle);
		break;
	case BT_FOOD_SPAWNER:
		_level->SpawnActor<FoodSpawner>(_size, _position, _angle);
		break;
	case BT_PLATE_SPAWNER:
		_level->SpawnActor<PlateSpawner>(_size, _position, _angle);
		break;
	case BT_CONVEYOR:
		_level->SpawnActor<Conveyor>(_size, _position, _angle);
		break;
	case BT_SINK:
		_level->SpawnActor<Sink>(_size, _position, _angle);
		break;
	case BT_COUNT:
	default:
		LOG(Error, "Invalid Type !!!");
		return;
	}

	/*const vector<BlockType>& _verbosityColors =
	{
		BT_WORK_PLAN,
		BT_GARBAGE_CAN,
		BT_CHOPPING_STATION,
		BT_STOVE,
		BT_FOOD_SPAWNER,
		BT_PLATE_SPAWNER,
		BT_CONVEYOR,
		BT_SINK,
		BT_COUNT
	};

	_level->SpawnActor<_verbosityColors[_type]>(_size, _position, _angle);*/
}

BlockType LevelLoader::GetBlockTypeByText(const string& _text) const
{
	if (_text == "BT_WORK_PLAN") return BT_WORK_PLAN;
	else if (_text == "BT_GARBAGE_CAN") return BT_GARBAGE_CAN;
	else if (_text == "BT_CHOPPING_STATION") return BT_CHOPPING_STATION;
	else if (_text == "BT_STOVE") return BT_STOVE;
	else if (_text == "BT_FOOD_SPAWNER") return BT_FOOD_SPAWNER;
	else if (_text == "BT_PLATE_SPAWNER") return BT_PLATE_SPAWNER;
	else if (_text == "BT_CONVEYOR") return BT_CONVEYOR;
	else if (_text == "BT_SINK") return BT_SINK;

	LOG(Error, "Invalid Text !!!");
	return BT_COUNT;
}

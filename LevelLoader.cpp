#include "LevelLoader.h"
#include "MeshComponent.h"
#include "LevelManager.h"
#include "Utilities.h"
#include "MeshActor.h"

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
	string _path = "ball_2";

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
				MeshActor* _mesh = _level->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(_size.x, _size.y), _path));
				_mesh->GetMesh()->SetOriginAtMiddle();
				_mesh->GetMesh()->GetShape()->SetPosition(Vector2f(_pos.x * _defaultSize.x + _rowIndex * _defaultSize.x,
																   _pos.y * _defaultSize.y + _colIndex * _defaultSize.y));
				_mesh->Rotate(Angle(degrees(_angle)));
			}
		}
		_count = Vector2u(1, 1);
	}
}


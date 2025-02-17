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
	Vector2f _size;
	Vector2f _pos;
	string _type;
	float _angle;

	string _token;

	Level* _level = M_LEVEL.GetCurrentLevel();

	for (u_int _index = 0; _index < _info.size(); _index++)
	{
		stringstream _stream = stringstream(_info[_index]);

		_pos.x = stof(GetStringUntilChar(_stream, '|'));
		_pos.y = stof(GetStringUntilChar(_stream, '|'));

		_size.x = stof(GetStringUntilChar(_stream, '|'));
		_size.y = stof(GetStringUntilChar(_stream, '|'));

		_angle = stof(GetStringUntilChar(_stream, '|'));

		_type = GetStringUntilChar(_stream, '|');

		
		MeshActor* _mesh = _level->SpawnActor<MeshActor>(RectangleShapeData(Vector2f(_size.x, _size.y), "Ball_2"));
		_mesh->GetMesh()->SetOriginAtMiddle();
		_mesh->GetMesh()->GetShape()->SetPosition(Vector2f(_pos.x * _size.x, _pos.y * _size.y));
		_mesh->Rotate(Angle(degrees(_angle)));
	}
}


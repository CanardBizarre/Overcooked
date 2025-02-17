#include "LevelLoader.h"
#include "MeshComponent.h"
#include "LevelManager.h"
#include "Utilities.h"

LevelLoader::LevelLoader()
{

}

void LevelLoader::InterpretString()
{
	vector<string> _info;

	Vector2f _size;
	Vector2f _pos;
	string _type;

	string _token;

	for (u_int _index = 0; _index < _info.size(); _index++)
	{
		stringstream _stream(_info[_index]);

		getline(_stream, _token, '|');
		_pos.x = stof(_token);
		getline(_stream, _token, '|');
		_pos.y = stof(_token);
		getline(_stream, _token, '|');
		_size.x = stof(_token);
		getline(_stream, _token, '|');
		_size.y = stof(_token);
		getline(_stream, _token, '|');
		_type = _token;

		//MeshComponent* _mesh = Spawn<MeshComponent>(M_LEVEL.GetCurrentLevel(), RectangleShapeData(Vector2f(_size.x, _size.y), ""));
		//_mesh->GetShape()->SetPosition(Vector2f(_pos.x, _pos.y));
	}


	cout << "PosX : " << _pos.x << "\nPosY : " << _pos.y << "\nSizeX : " << _size.x << "\nSizeY : " << _size.y << "\nTYPE : " << _type << endl;
}


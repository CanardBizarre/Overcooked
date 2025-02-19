#include "Utilities.h"

u_int GetUniqueID()
{
	static u_int _id = 0;
	return ++_id;
}

int GetRandomNumberInRange(const int _min, const int _max)
{
    random_device _rSeed; // Obtient un graine aléatoire
    mt19937 _gen(_rSeed()); // Initialise le générateur avec la graine
    uniform_int_distribution<> _distr(_min, _max); // Définit la distribution (les limites)

    return _distr(_gen); // Génération du nombre
}

float DegToRad(const float _degrees)
{
    return _degrees * pi / 180.0f;
}

float RadToDeg(const float _radians)
{
    return 180.0f / pi * _radians;
}

float Lerp(const float _start, const float _end, const float _time)
{
    return _start + _time * (_end - _start);
}

float Lerp_Constant(const float _start, const float _end, const float _time)
{
    return (1 - _time) * _start + _time * _end;
}

float DotProduct(const Vector2f& _direction, const Vector2f& _normal)
{
    return _direction.x * _normal.x + _direction.y * _normal.y;
}

float EaseOutQuart(const float _time)
{
    return 1 - powf(1 - _time, 4.0f);
}

float EaseInQuart(const float _time)
{
    return _time * _time * _time * _time;
}
float easeOutBounce(float _number)
{
    const float n1 = 7.5625f;
    const float d1 = 2.75f;

    if (_number < 1 / d1)
    {
        return n1 * _number * _number;
    }
    else if (_number < 2 / d1)
    {
      return n1 * (_number -= 1.5f / d1) * _number + 0.75f;
    }
     else if (_number < 2.5f / d1)
    {
      return n1 * (_number -= 2.25f / d1) * _number + 0.9375f;
    }
     else
    {
      return n1 * (_number -= 2.625f / d1) * _number + 0.984375f;
    }
}


float Length(const Vector2f& _vector)
{
    return sqrtf(powf(_vector.x, 2.0f) + powf(_vector.y, 2.0f));
}

void Normalize(Vector2f& _vector)
{
    _vector /= Length(_vector);
}

float Distance(const float _first, const float _second)
{
    return abs(_first - _second);
}

float Distance(const Vector2f& _first, const Vector2f& _second)
{
    return sqrtf(pow(_second.x - _first.x, 2.0f) + pow(_second.y - _first.y, 2.0f));
}

Vector2f ComputeNormal(const FloatRect& _rect)
{
    const Vector2f& _normal = Vector2f(-_rect.size.y, _rect.size.x);
    const float _norme = Length(_normal);
    return _normal / _norme;
}

vector<string> SplitString(const string& _string, const char _delimiter)
{
    vector<string> _result;
    stringstream _ss = stringstream(_string);
    string _item;

    while (getline(_ss, _item, _delimiter))
    {
        _result.push_back(_item);
    }

    return _result;
}
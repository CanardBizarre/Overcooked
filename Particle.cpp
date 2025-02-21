#include "Particle.h"
#include "TimerManager.h"

ParticleActor::ParticleActor(Level* _level, const u_int& _count, const float _maxLifeTime, 
							 const Color& _color, const PrimitiveType& _type)
						   : VertexActor(_level, _count, _type, "Particle")
{
	maxLifeTime = _maxLifeTime;
	particles = vector<Particle>(_count);
	isEmitting = true;

	new Timer([&]()
		{
			StopEmitting();
		}, seconds(_maxLifeTime), true, false);
}

ParticleActor::ParticleActor(const ParticleActor& _other) : VertexActor(_other)
{
	maxLifeTime = _other.maxLifeTime;
	particles = _other.particles;
}

void ParticleActor::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	int _index = 0;
	bool hasActiveParticles = false; // Vérifie si au moins une particule est active

	for (Particle& _particle : particles)
	{
		if (_particle.lifeTime > 0.0f)
		{
			_particle.lifeTime -= _deltaTime;
			hasActiveParticles = true;
		}

		Vertex& _vertex = GetVertexByIndex(_index++);

		if (_particle.lifeTime <= 0.0f)
		{
			//StopEmitting();
			if (isEmitting) // On ne réinitialise que si l'émission est active
			{
				Reset(_particle);
				_vertex.position = GetPosition();
				hasActiveParticles = true; // Une nouvelle particule a été créée
			}
			else
			{
				_vertex.color.a = 0; // Rendre la particule invisible
				continue;
			}
		}

		_vertex.position += _particle.velocity * _deltaTime;
		float ratio = _particle.lifeTime / maxLifeTime;
		_vertex.color.a = CAST(uint8_t, ratio * 255);
	}

	// Si aucune particule n'est active et qu'on a arrêté l'émission, on peut supprimer l'actor
	if (!hasActiveParticles && !isEmitting)
	{
		Destroy(); // Suppression de l'actor si nécessaire
	}
}



void ParticleActor::Reset(Particle& _particle)
{
	float angleRadians = GetRandomNumberInRange(0.0f, 360.0f) * (pi / 180.0f);
	float speed = GetRandomNumberInRange(50.0f, 100.0f);

	_particle.velocity = Vector2f(cos(angleRadians) * speed, sin(angleRadians) * speed);
	_particle.lifeTime = GetRandomNumberInRange(1.0f, 3.0f);
}
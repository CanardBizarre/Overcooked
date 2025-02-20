#pragma once
#include "VertexActor.h"

struct Particle
{
	float lifeTime;
	Vector2f velocity;
};

class ParticleActor : public VertexActor
{
	float maxLifeTime;
	vector<Particle> particles;
	bool isEmitting;

public:
	ParticleActor(Level* _level, const u_int& _count, const float _maxLifeTime = 1.0f,
				  const Color& _color = Color::White, const PrimitiveType& _type = PrimitiveType::Points);
	ParticleActor(const ParticleActor& _other);

	virtual void Tick(const float _deltaTime) override;

	void StartEmitting()
	{
		isEmitting = true;
	}

	void StopEmitting()
	{
		isEmitting = false;
	}

public:
	void Reset(Particle& _particle);
};
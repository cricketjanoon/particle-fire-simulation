#include "Swarm.h"

namespace CJ
{
	Swarm::Swarm()
	{
		_particles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm()
	{
		delete[] _particles;
	}
	void Swarm::Update()
	{
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			_particles[i].Update();
		}
	}
}
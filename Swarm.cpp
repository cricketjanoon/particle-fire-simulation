#include "Swarm.h"

namespace CJ
{
	Swarm::Swarm() : lastTime(0)
	{
		_particles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm()
	{
		delete[] _particles;
	}
	void Swarm::Update(int elapsedTime)
	{
		int interval = elapsedTime - lastTime;

		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			_particles[i].Update(interval);
		}

		lastTime = elapsedTime;


	}
}
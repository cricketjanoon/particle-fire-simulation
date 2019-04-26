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
}
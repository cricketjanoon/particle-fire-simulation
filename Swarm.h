#include "Particle.h"
#pragma once
namespace CJ
{
	class Swarm
	{
	private:
		Particle*  _particles;

	public:
		const static int NPARTICLES = 5000;
		Swarm();
		~Swarm();
		const Particle* const GetParticles() { return _particles; };
	};
}

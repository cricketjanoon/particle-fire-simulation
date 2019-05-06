#include "Particle.h"
#pragma once
namespace CJ
{
	class Swarm
	{
	private:
		Particle*  _particles;
		int lastTime;

	public:
		const static int NPARTICLES = 2000;
		Swarm();
		void Update(int elapsedTime);
		~Swarm();
		const Particle* const GetParticles() { return _particles; };
	};
}

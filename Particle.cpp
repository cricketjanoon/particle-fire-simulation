#include "Particle.h"
#include "Screen.h"
#include <math.h>
#include <stdlib.h>

namespace CJ
{
	Particle::Particle() : x(0), y(0)
	{
		direction = (2 * M_PI *rand()) / RAND_MAX;
		speed = (0.0001 * rand()) / RAND_MAX;
	}

	void Particle::Update(int interval)
	{
		double xspeed = speed * cos(direction);
		double yspeed = speed * sin(direction);

		x += xspeed * interval;
		y += yspeed * interval;

	}

	Particle::~Particle()
	{
	}
}
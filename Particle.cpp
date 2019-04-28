#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>

namespace CJ
{
	Particle::Particle()
	{
		x = (2.0 * rand() / RAND_MAX) - 1;
		y = (2.0 *rand() / RAND_MAX) - 1;

		x_speed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
		y_speed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	}

	void Particle::Update()
	{
		x += x_speed;
		y += y_speed;

		if (x < -1 || x > 1)
			x_speed = -x_speed;
		if (y < -1 || y>1)
			y_speed = -y_speed;
	}

	Particle::~Particle()
	{
	}
}
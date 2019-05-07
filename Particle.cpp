#include "Particle.h"
#include "Screen.h"
#include <math.h>
#include <stdlib.h>

namespace CJ
{
	Particle::Particle() : x(0), y(0)
	{
		
		Init();
	}

	void Particle::Init() 
	{
		x = 0;
		y = 0;

		direction = (2 * M_PI *rand()) / RAND_MAX;
		speed = (0.02 * rand()) / RAND_MAX;

		speed *= speed;
	}


	void Particle::Update(int interval)
	{
		direction += interval * 0.0002;


		double xspeed = speed * cos(direction);
		double yspeed = speed * sin(direction);

		x += xspeed * interval;
		y += yspeed * interval;

		if(x < -1 || x >1 || y <-1 || y >1)
		{
			Init();
		}

		if (rand() < RAND_MAX / 100)
		{
			Init();
		}


	}
}
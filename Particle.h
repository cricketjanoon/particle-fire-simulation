#include <stdlib.h>

#pragma once
namespace CJ
{
	struct Particle
	{
		double x;
		double y;
		double x_speed;
		double y_speed;

		Particle();
		void Update();
		~Particle();
	};
}

#include <stdlib.h>

#pragma once
namespace CJ
{
	struct Particle
	{
		double x;
		double y;

		double speed;
		double direction;

		Particle();
		void Update(int interval);
		void Init();

	};
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include "Screen.h"
#include <time.h>
#include "Swarm.h"

using namespace std;
using namespace CJ;

int main(int argc, char* argv[])
{
	Swarm swarm;
	Screen screen;

	if (screen.Init() == false)
	{
		cout << "Error initializing SDL.";
	}

	while (true)
	{
		//	//Update particles
		//	//draw particles
		//	//check for messages

		int elapsed = SDL_GetTicks();

		screen.Clear();
		swarm.Update(elapsed);

		unsigned char green = (1 + sin(elapsed*0.0001)) * 128;
		unsigned char red = (1 + cos(elapsed*0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed*0.0003)) * 128;

		//cout << green << endl;

		/*for (int y = 0; y < Screen::SCREEN_HEIGHT; ++y)
		{
			for (int x = 0; x < Screen::SCREEN_WIDTH; ++x)
			{
				screen.SetPixel(x, y, red, green, blue);
			}
		}*/

		const Particle* const particles = swarm.GetParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = particles[i];

			int x = (particle.x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.y * Screen::SCREEN_WIDTH / 2) + (Screen::SCREEN_HEIGHT/2);

			screen.SetPixel(x, y, 255, 255, 255);
		}

		screen.Update();

		if (screen.ProcessEvent() == false)
			break;
	}

	return 0;
}
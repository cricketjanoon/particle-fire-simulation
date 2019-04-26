#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <SDL.h>
#include <math.h>
#include "Screen.h"

using namespace std;
using namespace cj;

int main(int argc, char* argv[])
{
	//0xFF123456

	unsigned char alpha = 0xFF;
	unsigned char red = 0x12;
	unsigned char green = 0x34;
	unsigned char blue = 0x56;

	unsigned int color = 0;

	color += alpha;
	color <<= 8;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;

	cout << setfill('0') << setw(8) << hex << color << endl;

	Screen screen;

	if (screen.Init() == false)
	{
		cout << "Error initializing SDL.";
	}

	int max = 0;

	while (true)
	{
		//Update particles
		//draw particles
		//check for messages

		int elapsed = SDL_GetTicks();
		unsigned char green = (1 + sin(elapsed*0.0001)) * 128;
		unsigned char red = (1 + cos(elapsed*0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed*0.0003)) * 128;

		//cout << green << endl;

		for (int y = 0; y < Screen::SCREEN_HEIGHT; ++y)
		{
			for (int x = 0; x < Screen::SCREEN_WIDTH; ++x)
			{
				screen.SetPixel(x, y, red, green, blue);
			}
		}

		screen.Update();

		if (screen.ProcessEvent() == false)
			break;
	}

	return 0;
}
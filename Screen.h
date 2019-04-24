#include <SDL.h>
#include <iostream>
using namespace std;

namespace cj
{
#pragma once
	class Screen
	{
	private:
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		SDL_Texture* _texture;
		Uint32* _buffer;

	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;
		Screen();
		bool Init();
		bool ProcessEvent();
		void Close();
		void Update();
		~Screen();
	};
}
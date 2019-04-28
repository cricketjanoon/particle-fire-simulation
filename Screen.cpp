#include "Screen.h"

namespace CJ
{
	Screen::Screen() : _window(NULL), _renderer(NULL), _texture(NULL), _buffer(NULL)
	{
	}

	bool Screen::Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			return false;
		}

		_window = SDL_CreateWindow("Particle System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (_window == NULL)
		{
			SDL_Quit();
			return false;
		}

		_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
		_texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (_renderer == NULL)
		{
			SDL_DestroyWindow(_window);
			SDL_Quit();
			return false;
		}
		if (_texture == NULL)
		{
			SDL_DestroyRenderer(_renderer);
			SDL_DestroyWindow(_window);
			SDL_Quit();
			return false;
		}

		_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		memset(_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		//_buffer[3600] = 0xFFFFFFFF;

		//Black: 0xFF000000
		//Red:   0x00FF0000
		//Green: 0x0000FF00
		//Blue:  0x000000FF
		//Yellow: 0x00FFFF00

	/*	for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; ++i)
		{
			_buffer[i] = 0x00FFFF00;
		}
*/
		return true;
	}

	bool Screen::ProcessEvent()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return false;
			}
		}
		return true;
	}

	void Screen::Close()
	{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyTexture(_texture);
		SDL_DestroyWindow(_window);
		SDL_Quit();
	}

	void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
	{
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
			return;

		Uint32 color = 0;
		color += 0xFF;
		color <<= 8;
		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;

		_buffer[(y*SCREEN_WIDTH) + x] = color;
	}

	void Screen::Update()
	{
		SDL_UpdateTexture(_texture, NULL, _buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(_renderer);
		SDL_RenderCopy(_renderer, _texture, NULL, NULL);
		SDL_RenderPresent(_renderer);
	}

	void Screen::Clear()
	{
		memset(_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(Uint32));
	}

	Screen::~Screen()
	{
	}
}
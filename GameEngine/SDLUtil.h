#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>


bool Init()
{
	bool bSuccess = true;
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL::Error SDL Could Not Be Initialized : %s\n", SDL_GetError());
		bSuccess = false;
	}

	// initialize SDL_Image for image loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_IMG::Error SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		bSuccess = false;
	}

	// initialize SDL_ttf for font loading
	if (TTF_Init() == -1)
	{
		printf("SDL_TTF::Error SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		bSuccess = false;
	}

	return bSuccess;
}

SDL_Window* CreateWindow(int x, int y, int w, int h, std::string WindowTitle = "", Uint32 _Flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)
{
	SDL_Window* _Create = SDL_CreateWindow(WindowTitle.c_str(), x, y, w, h, _Flags);
	if (_Create == NULL)
	{
		printf("SDL::Error SDL_Window could not be created %s", SDL_GetError());
	}
	return _Create;
}

SDL_Renderer* CreateRenderer(SDL_Window* _window, Uint32 _Flags = SDL_RENDERER_ACCELERATED)
{
	SDL_Renderer* _Create = SDL_CreateRenderer(_window, -1, _Flags);
	if (_Create == NULL)
	{
		printf("SDL::Error SDL_Renderer could not be created %s", SDL_GetError());
	}
	return _Create;
}
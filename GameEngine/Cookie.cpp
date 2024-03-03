#include "Cookie.h"

#include <stdio.h>
#include <cstdlib>

const int IMAGESIZE = 200;

const char* COOKIEPATH = "img/CookieImage.png";

Cookie::Cookie(SDL_Renderer* _renderer)
{
	_CookieRenderer = _renderer;
	_CookieTex = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(COOKIEPATH);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", COOKIEPATH, IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		_CookieTex = SDL_CreateTextureFromSurface(_CookieRenderer, loadedSurface);
		if (_CookieTex == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", COOKIEPATH, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	x = y = (SCREEN_WIDTH / 2) - (IMAGESIZE / 2);
	w = h = IMAGESIZE;
	
}

SDL_Texture* Cookie::GetTexture()
{
	if (IsValid())
		return _CookieTex;
	else
		return NULL;
}

SDL_Rect Cookie::GetRect()
{
	SDL_Rect _CookieRect{
		x,
		y,
		w,
		h
	};
	return _CookieRect;
}

bool Cookie::PosInBounds(int xPos, int yPos)
{
	if (xPos < x || xPos > x + w)
		return false;
	if (yPos < y || yPos > y + h)
		return false;
	return true;
}

void Cookie::Broadcast()
{
	x = rand() % (SCREEN_WIDTH - w);
	y = rand() % (SCREEN_HEIGHT - h);
}

//Using SDL and standard IO
#include <stdio.h>
#include "Cookie.h"
#include "TextRenderer.h"
#include "DelegateSystem.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

#include "SDLUtil.h"

void Update(SDL_Renderer* _renderer, Cookie& _Cookie, TextRenderer& _TextRenderer);


int main(int argc, char* args[])
{

	//The window we'll be rendering to
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL; // the window's rendering surface

	if (!Init())
	{
		return -1;
	}

	window = CreateWindow(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, "Whack-A-Cookie");

	renderer = CreateRenderer(window);
	if (!window)
	{
		return -1;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(renderer, 1024, 768);
	
	//Nee to Delete in a Bit
	bool pikachuMoveRight = false;
	
	Cookie _ClickableCookie(renderer);
	DelegateSystem::getInstance()->RegisterObserver(&_ClickableCookie);

	TextRenderer _ScoreText(renderer);
	DelegateSystem::getInstance()->RegisterObserver(&_ScoreText);


	SDL_Event e; bool quit = false;

	// while the user doesn't want to quit
	while (quit == false)
	{
		SDL_GetTicks(); // can be used, to see, how much time in ms has passed since app start


		// loop through all pending events from Windows (OS)
		while (SDL_PollEvent(&e))
		{
			// check, if it's an event we want to react to:
			switch (e.type) {
				case SDL_QUIT: {
					quit = true;
				} break;

					// This is an example on how to use input events:
				case SDL_MOUSEBUTTONDOWN: {
					int MousePosX = e.button.x;
					int MousePosY = e.button.y;
					if (_ClickableCookie.PosInBounds(MousePosX, MousePosY))
					{
						DelegateSystem::getInstance()->ProcessBroadcast();
					}
				} break;
			} 
		}
		
		Update(renderer, _ClickableCookie, _ScoreText);

		SDL_Delay(0); // can be used to wait for a certain amount of ms
	}

	return 0;
}



void Update(SDL_Renderer* _renderer, Cookie& _Cookie, TextRenderer& _TextRenderer)
{

	// clear the screen
	SDL_SetRenderDrawColor(_renderer, 120, 60, 255, 255);
	SDL_RenderClear(_renderer);

	SDL_Rect targetRectangle = _Cookie.GetRect();
	SDL_RenderCopy(_renderer, _Cookie.GetTexture(), NULL, &targetRectangle);

	// render the text
	targetRectangle = SDL_Rect{
		((SCREEN_WIDTH / 2) - (_TextRenderer.width / 2)),
		10 + (_TextRenderer.height / 2),
		_TextRenderer.width,
		_TextRenderer.height
	};
	SDL_RenderCopy(_renderer, _TextRenderer.GetTexture(), NULL, &targetRectangle);

	// present screen (switch buffers)
	SDL_RenderPresent(_renderer);
}


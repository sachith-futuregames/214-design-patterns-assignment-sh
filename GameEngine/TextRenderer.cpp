#include "TextRenderer.h"
#include <stdio.h>
#include <string>

TextRenderer::TextRenderer(SDL_Renderer* _renderer)
{
	score = -1;
	// load font
	FontType = TTF_OpenFont("font/lazy.ttf", 100);
	if (FontType == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	}
	_rendererCache = _renderer;
	IncrementScore();
}

void TextRenderer::IncrementScore()
{
	++score;
	// create text from font
	SDL_Color textColor = { 0xff, 0xff, 0xff };

	// render the text into an unoptimized CPU surface
	std::string DisplayText = "Score " + std::to_string(score);
	SDL_Surface* textSurface = TTF_RenderText_Solid(FontType, DisplayText.c_str(), textColor);
	int textWidth, textHeight;
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		// Create texture GPU-stored texture from surface pixels
		textTexture = SDL_CreateTextureFromSurface(_rendererCache, textSurface);
		if (textTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		// Get image dimensions
		width = textSurface->w;
		height = textSurface->h;
		//Get rid of old loaded surface
		SDL_FreeSurface(textSurface);
	}
}

SDL_Texture* TextRenderer::GetTexture()
{
	if (textTexture)
		return textTexture;
	else
		return NULL;
}

void TextRenderer::Broadcast()
{
	IncrementScore();
}

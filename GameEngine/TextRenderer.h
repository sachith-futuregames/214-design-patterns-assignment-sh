#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "Observer.h"

class TextRenderer : public Observer
{
public:
	
	/// <summary>
	/// Paramterised Constructor to create a Texture for the text
	/// </summary>
	/// <param name="_renderer">Renderer Context</param>
	TextRenderer(SDL_Renderer* _renderer);

	/// <summary>
	/// Function that increments the Score and Updates the Text on the Screen
	/// </summary>
	void IncrementScore();

	SDL_Texture* GetTexture();

	/// <summary>
	/// Width dimension of the Texture image
	/// </summary>
	int width;

	/// <summary>
	/// HEight Dimension of the Texture Image
	/// </summary>
	int height;


	// Inherited via Observer
	void Broadcast() override;

private:
	/// <summary>
	/// internal Cache of the Score
	/// </summary>
	int score;

	/// <summary>
	/// Cached Reference of the Renderer
	/// </summary>
	SDL_Renderer* _rendererCache;

	/// <summary>
	/// Cached Reference of the Loaded Font Type
	/// </summary>
	TTF_Font* FontType;

	/// <summary>
	/// Internal Cache of the Texture;
	/// </summary>
	SDL_Texture* textTexture;
};


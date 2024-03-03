#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Observer.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


class Cookie : public Observer
{
public:
	/// <summary>
	/// PArameterised Constructor
	/// Used to Set the Initial Value of the Cookie and the LOad the IMage of the Cookie. 
	/// </summary>
	Cookie(SDL_Renderer* _Renderer);

	/// <summary>
	/// Public Getter for the Texture Pointer of the Cookie
	/// </summary>
	/// <returns> returns the Cookie texture as an SDL Texture </returns>
	SDL_Texture* GetTexture();

	/// <summary>
	/// Public Getter for the SDL Rect of the Cookie
	/// </summary>
	/// <returns>returns the Cookie Rect as a </returns>
	SDL_Rect GetRect();

	/// <summary>
	/// Dimensions of the Rectangle of the Image
	/// </summary>
	int x, y, w, h;

	bool PosInBounds(int xPos, int yPos);

	// Inherited via Observer
	void Broadcast() override;

	inline bool IsValid() const { return _CookieTex; }

private:

	/// <summary>
	/// Cache to store the Reference to the Texture Created
	/// </summary>
	SDL_Texture* _CookieTex;

	

	/// <summary>
	/// Cache to store the Reference of the Renderer used
	/// </summary>
	SDL_Renderer* _CookieRenderer;


	

};


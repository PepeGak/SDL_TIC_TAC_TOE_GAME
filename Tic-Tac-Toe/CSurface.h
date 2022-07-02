#pragma once
#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdio>

class CSurface
{
public:
	CSurface();

	static SDL_Surface* LoadSurface(const char* fileName, SDL_Surface* screenSurface);
	static SDL_Surface* LoadSurface(const char* fileName, SDL_Surface* screenSurface, int r, int g, int b);
	
	static void drawSurface(SDL_Surface* source, SDL_Surface* destination, int x, int y);
	static void drawSurface(SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip, int x, int y);
	static void drawSurface(SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip, SDL_Rect* scale);
	
	static void drawFont(TTF_Font* font, SDL_Surface* screen, const char* text, int x, int y, int r, int g, int b);

private:

};

#endif // !_CSURFACE_H_

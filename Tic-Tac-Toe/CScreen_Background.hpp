#pragma once
#ifndef _CSCREEN_BACKGROUND_H_
#define _CSCREEN_BACKGROUND_H_

#include "CScreen.hpp"
class CScreen_Background : public CScreen
{
public:
	CScreen_Background(const char* filePath);
	CScreen_Background(const char* filePath, SDL_Surface* screenDest);
	~CScreen_Background();
	void drawSurface(int x, int y) override;
	void drawSurface(int x, int y, SDL_Surface* screenDest) override;

private:
	SDL_Surface* background;
};

#endif

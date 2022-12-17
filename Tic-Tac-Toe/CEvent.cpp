#include "CEvent.hpp"

CEvent::CEvent()
{
	this->isQuit = false;
};

CEvent::~CEvent()
{

};

void CEvent::onEvent(SDL_Event* ev) //Используется
{
	switch (ev->type)
	{
	case SDL_QUIT:
		{
			this->isQuit = true;
			this->onExit();
			break;
		}
	case SDL_KEYDOWN:
		this->onKeyDown(ev->key.keysym.sym, ev->key.keysym.mod, ev->key.keysym.scancode);
		break;

	case SDL_MOUSEMOTION:
		this->onMouseMove(ev->motion.x, ev->motion.y, ev->motion.xrel, ev->motion.yrel, ev->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT), ev->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT), ev->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE));
		break;

	case SDL_TEXTINPUT:
		this->onTextInput(ev->text.text);
		break;

	case SDL_MOUSEBUTTONDOWN:
		switch (ev->button.button)
		{
		case SDL_BUTTON_LEFT:
			this->onLButtonDown(ev->button.x, ev->button.y);
			break;

		default:
			break;
		}
		break;

	case SDL_WINDOWEVENT:
		switch (ev->window.event)
		{
		case SDL_WINDOWEVENT_CLOSE:
			ev->type = SDL_QUIT;
			SDL_PushEvent(ev);
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}
};

void CEvent::onExit() //Используется
{
	
};

void CEvent::onKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode) //Используется
{
	switch (sym)
	{
	case SDLK_ESCAPE:
		this->isQuit = false;
		this->onExit();
		break;

	case SDLK_DOWN:
		this->onArrowDownDown();
		break;

	case SDLK_UP:
		this->onArrowUpDown();
		break;

	case SDLK_LEFT:
		this->onArrowLeftDown();
		break;

	case SDLK_RIGHT:
		this->onArrowRightDown();
		break;

	case SDLK_RETURN:
		this->onReturn();
		break;

	case SDLK_BACKSPACE:
		this->onBackspaceDown();
		break;

	default:
		break;
	}
};

void CEvent::onMouseMove(int xm, int ym, int relx, int rely, bool left, bool right, bool middle) //Используется
{

};

void CEvent::onArrowDownDown() //Используется
{

};

void CEvent::onArrowUpDown() //Используется
{

};

void CEvent::onArrowLeftDown() //Используется
{

};

void CEvent::onArrowRightDown() //Используется
{

};

void CEvent::onTextInput(char* text) //Используется
{

};

void CEvent::onBackspaceDown() //Используется
{

};

void CEvent::onReturn() //Используется
{

};


void CEvent::onLButtonDown(int xm, int ym) //Используется
{
	
};


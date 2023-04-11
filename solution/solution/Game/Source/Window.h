#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "Module.h"
#include "SDL/include/SDL.h"

struct SDL_Window;
struct SDL_Surface;

class Window : public Module
{
public:

	Window();

	// Destructor
	virtual ~Window();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before quitting
	bool CleanUp();

	// Changae title
	void SetTitle(const char* title);

	// Retrive window size
	void GetWindowSize(uint& width, uint& height) const;

	// Retrieve window scale
	int GetScale() const;

	int GetWidth() const;

	int GetHeight() const;	//no pot fade to black amb unsigned int

	bool ResizeWin();

public:
	// The window we'll be rendering to
	SDL_Window* window;

	// The surface contained by the window
	SDL_Surface* screenSurface;

	bool changeScreen;	// false - small screen / true - fullscreen
	
private:
	Uint32 flags = SDL_WINDOW_SHOWN;

	bool fullscreen;
	bool borderless;
	bool resizable;
	bool fullscreen_window;


	SString title;
	uint width;
	uint height;
	uint scale;
	
};

#endif // __WINDOW_H__
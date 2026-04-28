#ifndef APP_H
#define APP_H

typedef struct
{
	// responsible for handling ncurses.h
	float a;
} Window;

typdef struct
{
	Window* window;
} App;

void App_Run(App* app);

#endif

#pragma once
#ifndef _SPLASH_H
#define _SPLASH_H

//include i namespace
#include "Scene.h"
#include "Renderer.h"

#include <cstdio>
#include <ctime>

using namespace std;

class Splashscreen : public Scene {
private:
	void init();
	SDL_Rect rectAnimation{ 200,300,NULL,NULL };

public:
	Splashscreen();
	void EventHandle();
	void Update();
	void Draw();
	~Splashscreen();
};

#endif
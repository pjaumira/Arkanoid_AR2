#pragma once
#ifndef _LEVEL_H
#define _LEVEl_H

#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Powerup.h"

using namespace std;

class Level : public Scene {
private :
	//text
	Text userScore{ "textScore", "0000", 255, 255, 255, 0, 250, 100 };
	Text timer{ "textTimer", "00:00", 255, 255, 255,0, 305, 100 };
	//Rects
	SDL_Rect rectScore{ 300, 230, NULL, NULL };
	SDL_Rect rectTimer{ 260, 300, NULL, NULL };
};

#endif
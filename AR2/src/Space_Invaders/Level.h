#pragma once
#ifndef _LEVEL_H
#define _LEVEl_H

//includes SDL
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

//includes generics
#include <iostream>
#include "string"
#include <algorithm> 
#include <map>
#include <vector>
#include <cstdlib>
#include <sstream>

//XML
#include "../../dep/inc/XML/rapidxml.hpp"
#include "../../dep/inc/XML/rapidxml_utils.hpp"
#include "../../dep/inc/XML/rapidxml_iterators.hpp"
#include "../../dep/inc/XML/rapidxml_print.hpp"

using namespace std;

class Level : public Scene {
private :
	//text
	Text userScore{ "textScore", "0000", 255, 255, 255, 0, 250, 100 };
	Text timer{ "textTimer", "00:00", 255, 255, 255,0, 305, 100 };
	//Rects
	SDL_Rect rectScore{ 300, 230, NULL, NULL };
	SDL_Rect rectTimer{ 260, 300, NULL, NULL };

	//funcions
	void initEnemies();
	void initHud();

	enum Enemies {NORMAL, HEAVY, EMPTY, EXPLOSION};

	struct Cell{
		SDL_Rect rect;
		Enemies enemy;
	};

	SDL_Rect rectEnemies = {};
	SDL_Rect rectScore2 = {};
	SDL_Rect rectTimer2 = {};
	SDL_Rect rectPowerUp = {};
	clock_t time;
	float actualTime;
	float deltaTime = 0;
	int frameTime = 0;

	void checkEndCondition();

	//fer arrays amb columnes i files de enemics

	void spawnPowerUp();
	void drawHud();
	SDL_Rect getRect(std::string);
	void resizeRectTexture(Vector2, std::string);

public:
	Level();
	map<pair<int, int>, Cell*> m_map;
	void EventHandle();
	void Update();
	void Draw();
};

#endif
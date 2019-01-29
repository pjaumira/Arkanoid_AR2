#pragma once
#ifndef _GAME_H
#define _GAME_H

//includes basics
#include <iostream>
#include "string"

//includes classes creades pel joc
#include "Scene.h"
#include "Menu.h"
#include "Level.h"
#include "Splashscreen.h"
#include "Ranking.h"

class Game {
private:

	//enum possible game states (segons doc)
	enum GameState{
		SPLASH, MENU, RANKING, PLAY, EXIT, PAUSE
	};

public:
	Game();
};

#endif
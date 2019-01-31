#pragma once
#include "Renderer.h"
#include "Types.h"

#include <time.h>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef _PLAYER_H
#define _PLAYER_H

class Player {

private :

	struct Bullet {
		Vector2 position;
	};

	struct PowerUp {
		clock_t time;
		float timer = 5;
		string type;
	};

public :

	SDL_Rect rectPlayerSprite{ 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT };

	string getPlayerTextScore();
	string getPlayerScore();

	float getPlayerXVel();
	void setPlayerXVel(string);

	SDL_Keycode Akey;
	SDL_Keycode Pkey;
	SDL_Keycode Dkey;
	SDL_Keycode Spacebarkey;

	bool hasPowerUp();
	bool isFast();
	bool doubleShot();

	void increaseScore(string);
	int getScore();

	Bullet bullet;
	PowerUp Powerup;

	void pickPowerUp(string);
	void resetPowerUp();

	int normalPoints;
	int heavyPoints;

private :

	int playerScore = 0;
	float playerXVel = 0;
	float  baseSpeed ;
	float  modSpeed ;

	bool m_bullet = true;
	bool speedPowerUp = false;
	bool doubleShotPowerUp = false;

	string playerTextScore;
	string playerScore2;
};

#endif
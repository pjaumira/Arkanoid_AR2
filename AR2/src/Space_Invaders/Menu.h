#pragma once
#ifndef _MENU_H
#define _MENU_H

//include i nmaespace
#include "Scene.h"

using namespace std;

//classe menu derivada de escena, que porta a les altres escenes del joc
class Menu : public Scene {
private:

	//text dels botons
	Text buttonTextLevel{ "textButtonLevel", "Play", 255, 255, 255, 0, 250, 100 };
	Text buttonTextRanking{ "textButtonRanking", "Ranking", 255, 255, 255,0, 305, 100 };
	Text buttonTextSoundOptions{ "textButtonSound", "Mute/Unmute", 255, 255, 255,0, 270, 100 };
	Text buttonTextExit{ "textButtonExit", "Exit",255, 255, 255, 0, 325, 100 };

	//rectangles dels botons
	SDL_Rect rectLevelButton{ 300, 230, NULL, NULL };
	SDL_Rect rectRankingButton{ 260, 300, NULL, NULL };
	SDL_Rect rectSoundOptionsButton{ 170, 370, NULL, NULL };
	SDL_Rect rectExitButton{ 310, 440, NULL, NULL };
	SDL_Point mousePoint;

	//funcions a declarar
	void updateSoundOptions();
	bool collision(SDL_Point, SDL_Rect);
	string selectedButton;
	void exit();

public:

	Menu();
	void EventHandle();
	void Update();
	void Draw();
	string getButton();
};

#endif
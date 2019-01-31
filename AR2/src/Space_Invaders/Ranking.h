#pragma once
#ifndef _RANKING_H
#define _RANKING_H

//includes classes del joc
#include "Renderer.h"
#include "Scene.h"

//includes base i SDL
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>

using namespace std;

class Ranking : public Scene {

private:

	//funcions d'apertura i escriptura del document
	void init();
	bool fileExists();
	void readFile();
	void writeFile();
	void printRanking();

	void insertNewScore(map<int, string>);
	bool checkIfHighScore(map<int, string>);

	int maxNum = 10;
	void checkMaxNumScore();

	map<int, string> ranking;
	SDL_Rect inputText{ SPRITE_WIDTH,SPRITE_HEIGHT,SPRITE_WIDTH * 3,SPRITE_HEIGHT };

	SDL_Point mousePoint;
	bool collision(SDL_Point, SDL_Rect);

	Text m_TextRanking1{ "Ranking1", "1 - 0 --------",255, 255, 255,0, 250, 150 };
	Text m_TextRanking2{ "Ranking2", "2 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking3{ "Ranking3", "3 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking4{ "Ranking4", "4 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking5{ "Ranking5", "5 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking6{ "Ranking6", "6 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking7{ "Ranking7", "7 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking8{ "Ranking8", "8 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking9{ "Ranking9", "9 - 0 --------", 255, 255, 255,0, 250, 150 };
	Text m_TextRanking10{ "Ranking10", "10 - 0 --------", 255, 255, 255,0, 250, 150 };

	Text m_TextExit{ "textExit", "Tornar Enrere",255, 255, 255, 0, 260, 150 };

	SDL_Rect rectRanking1{ 250, 120, NULL, NULL };
	SDL_Rect m_rectRanking2{ 250, 160, NULL, NULL };
	SDL_Rect m_rectRanking3{ 250, 200, NULL, NULL };
	SDL_Rect m_rectRanking4{ 250, 240, NULL, NULL };
	SDL_Rect m_rectRanking5{ 250, 280, NULL, NULL };
	SDL_Rect m_rectRanking6{ 250, 320, NULL, NULL };
	SDL_Rect m_rectRanking7{ 250, 360, NULL, NULL };
	SDL_Rect m_rectRanking8{ 250, 400, NULL, NULL };
	SDL_Rect m_rectRanking9{ 250, 440, NULL, NULL };
	SDL_Rect m_rectRanking10{ 250, 480, NULL, NULL };

	SDL_Rect m_rectReturnButton{ 165, 535, NULL, NULL };
	SDL_Rect getRect(int id);
	string getRectID(int id);

public:
	Ranking();
	Ranking(map<int, string>);
	void EventHandle();
	void Update();
	void Draw();
	~Ranking();
};

#endif //_RANKING_H
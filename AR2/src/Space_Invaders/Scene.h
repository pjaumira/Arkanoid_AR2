#pragma once
#ifndef _SCENE_H
#define _SCENE_H

//includes classes del joc + SDL
#include "Renderer.h"
#include "Types.h"
#include <map>

using namespace std;

class Scene {
public:
	Scene();
	enum SceneState	{
		RUNNING, EXIT, GOTO, PAUSED, START
	};

	SceneState GetState();

	//Virtual functions universals en les escenes
	virtual void EventHandle();
	virtual void Update();
	virtual void Draw();


	virtual map <int, string> getPlayersScore();
	virtual string getButton();


protected:
	SceneState sceneState;
	SDL_Rect rectBackground{ 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
};

#endif
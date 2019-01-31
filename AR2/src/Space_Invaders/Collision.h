#pragma once
#include <SDL.h>

//funcio per comprovar si hi ha colisions entre un punt i un Rect
bool collision(SDL_Point origin, SDL_Rect target) {
	return (origin.x > target.x && origin.x < target.x + target.w && origin.y > target.y && origin.y < target.y + target.h);
}
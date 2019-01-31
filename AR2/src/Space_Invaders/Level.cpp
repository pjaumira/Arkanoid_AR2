//
#include "Level.h"

//inicialitzar la grid d enemics

//inicialitzar el hud amb el contador i els punts

Level::Level() {
	sceneState = SceneState::RUNNING;
	Renderer::Instance()->LoadTexture("background", PATH_IMG + BG_GAME);
}

//moure la peça player d'acord amb els inputs
//activar la generacio de bullets al premer espai
//pausa al premer p/espai i tot el canvi de estat
//spawn de powerups
void Level::EventHandle() {

}

void Level::Update() {

}

//dibuixar enemics sobre grid i les explosions i bullets
void Level::Draw() {
	Renderer::Instance()->PushImage("background", rectBackground);
	Renderer::Instance()->Render();
}
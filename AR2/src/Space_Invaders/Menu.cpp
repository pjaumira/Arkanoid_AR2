//include classe
#include "Menu.h"

Menu::Menu() {

	//estat de la escena, activa els botons
	sceneState = SceneState::RUNNING;

	//carga dels textos
	Renderer::Instance()->LoadTexture("menu", PATH_IMG + BG_MENU);
	Renderer::Instance()->LoadTextureText("sunspire", buttonTextLevel);
	Renderer::Instance()->LoadTextureText("sunspire", buttonTextSoundOptions);
	Renderer::Instance()->LoadTextureText("sunspire", buttonTextRanking);
	Renderer::Instance()->LoadTextureText("sunspire", buttonTextExit);


	Vector2 v;

	v = Renderer::Instance()->GetTextureSize("textButtonLevel");
	rectLevelButton.w = v.x;
	rectLevelButton.h = v.y;

	v = Renderer::Instance()->GetTextureSize("textButtonRanking");
	rectRankingButton.w = v.x;
	rectRankingButton.h = v.y;

	v = Renderer::Instance()->GetTextureSize("textButtonSound");
	rectSoundOptionsButton.w = v.x;
	rectSoundOptionsButton.h = v.y;

	v = Renderer::Instance()->GetTextureSize("textButtonExit");
	rectExitButton.w = v.x;
	rectExitButton.h = v.y;
}

void Menu::EventHandle() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			//sortir del joc mitjançant input
		case SDL_QUIT:
			sceneState = SceneState::EXIT;
			break;
			//clicks en els botons de transicio
		case SDL_MOUSEBUTTONDOWN:

			mousePoint = { event.motion.x, event.motion.y };

			if (collision(mousePoint, rectLevelButton)) {
				selectedButton = "Play";
				sceneState = SceneState::GOTO;
			}
			else if (collision(mousePoint, rectSoundOptionsButton)) {
				updateSoundOptions();
			}
			else if (collision(mousePoint, rectRankingButton)) {
				selectedButton = "Ranking";
				sceneState = SceneState::GOTO;
			}
			else if (collision(mousePoint, rectExitButton)) {
				sceneState = SceneState::EXIT;
			}
			break;
		default:break;
		}
	}
}

//useless right now
void Menu::Update() {}

void Menu::Draw()
{
	Renderer::Instance()->Clear();

	//Draw del fons i els buttons sobre la escena
	Renderer::Instance()->PushImage("menu", rectBackground);
	Renderer::Instance()->PushImage("textButtonLevel", rectLevelButton);
	Renderer::Instance()->PushImage("textButtonSound", rectSoundOptionsButton);
	Renderer::Instance()->PushImage("textButtonRanking", rectRankingButton);
	Renderer::Instance()->PushImage("textButtonExit", rectExitButton);

	Renderer::Instance()->Render();
}

//us de la funcio colisio
bool Menu::collision(SDL_Point origin, SDL_Rect target) {
	return (origin.x > target.x && origin.x < target.x + target.w && origin.y > target.y && origin.y < target.y + target.h);
}

//silenciar la musica
void Menu::updateSoundOptions() {
	Renderer::Instance()->toggleMusic();
}

void Menu::exit() {}

//retorna el boto perque Game canvi escena
string Menu::getButton() {
	return selectedButton;
}
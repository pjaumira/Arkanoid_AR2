//include del header
#include "Splashscreen.h"
#include <chrono>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

Splashscreen::Splashscreen() {
	sceneState = SceneState::RUNNING;
	Renderer::Instance()->LoadTexture("splash", PATH_IMG + BG_SPLASH);
}

void Splashscreen::EventHandle() {
	SDL_Event event;
	sceneState = SceneState::GOTO;
}

void Splashscreen::Update() {}

void Splashscreen::Draw() {
	Renderer::Instance()->Clear();
	//Draw del fons i els buttons sobre la escena
	Renderer::Instance()->PushImage("splash", rectBackground);
	Renderer::Instance()->Render();
	sleep_for(3s);
}


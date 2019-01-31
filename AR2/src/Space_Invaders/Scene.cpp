#include "Scene.h"

Scene::Scene() {
	sceneState = SceneState::RUNNING;
}

Scene::SceneState Scene::GetState() {
	return sceneState;
}

//trio de funcions virtuals
void Scene::EventHandle() {}
void Scene::Update() {}
void Scene::Draw() {}

//getters
map<int, string> Scene::getPlayersScore()
{
	return map<int, string>();
}

string Scene::getButton()
{
	return string();
}

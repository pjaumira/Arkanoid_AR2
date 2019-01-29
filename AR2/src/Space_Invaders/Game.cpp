#include "Game.h"

Game::Game() {
	Renderer::Instance()->LoadFont(Font{ "sunspire",PATH_FONT + SUNSPIRE ,50 });

	map<int, string> score;
	string button;
	GameState gameState = GameState::SPLASH;
	Scene *m_currentScene;

	//cambiar a Splashscreen
	m_currentScene = new Splashscreen();
	while (gameState != GameState::EXIT) {
		switch (m_currentScene->GetState())
		{
		case Scene::SceneState::RUNNING:
			m_currentScene->EventHandle();
			m_currentScene->Update();
			m_currentScene->Draw();
			break;

		case Scene::SceneState::EXIT:
			switch (gameState)
			{
			case GameState::MENU:
				delete m_currentScene;
				m_currentScene = nullptr;
				gameState = GameState::EXIT;
				break;
			case GameState::PLAY:
				delete m_currentScene;
				m_currentScene = new Ranking(score);
				break;
			default:
				break;
			}
			break;

		case Scene::SceneState::GOTO:
			switch (gameState)
			{
			case GameState::SPLASH:
				delete m_currentScene;
				gameState = GameState::MENU;
				m_currentScene = new Menu();
				break;
			case GameState::MENU:
				button = m_currentScene->getButton();

				delete m_currentScene;
				if (button == "Ranking")
				{
					gameState = GameState::RANKING;
					m_currentScene = new Ranking();
				}
				else {
					gameState = GameState::PLAY;
					//if (button == "Play")
						//m_currentScene = new Level;
				}
				break;
			case GameState::PLAY:
				gameState = GameState::RANKING;
				score = m_currentScene->getPlayersScore();
				delete m_currentScene;
				m_currentScene = new Ranking(score);
				break;
			case GameState::RANKING:
				gameState = GameState::MENU;
				delete m_currentScene;
				m_currentScene = new Menu();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
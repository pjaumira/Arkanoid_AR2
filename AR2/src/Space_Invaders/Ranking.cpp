#include "Ranking.h"

//constructor base
Ranking::Ranking() {
	sceneState = SceneState::RUNNING;
	init();
	if (fileExists()) {
		readFile();
		printRanking();
	}
}

//constructor amb puntuacio
Ranking::Ranking(map<int, string> newScores) {
	sceneState = SceneState::RUNNING;
	init();

	if (fileExists()) {
		readFile();
		insertNewScore(newScores);
		if (checkIfHighScore(newScores)) {
			checkMaxNumScore();
		}
		printRanking();
		writeFile();
	}
	else {
		insertNewScore(newScores);
		writeFile();
	}
	checkMaxNumScore();
}

//inicialitzacio
void Ranking::init() {

	//fons
	Renderer::Instance()->LoadTexture("ranking", PATH_IMG + BG_RANKING);
	//text top 10
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking1);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking2);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking3);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking4);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking5);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking6);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking7);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking8);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking9);
	Renderer::Instance()->LoadTextureText("sunspire", m_TextRanking10);
	// text boto retorn menu
	Renderer::Instance()->LoadTextureText("sunspire", m_TextExit);

	Vector2 v;
	//textos top 10
	v = Renderer::Instance()->GetTextureSize("Ranking1");
	rectRanking1.w = v.x;
	rectRanking1.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking2");
	m_rectRanking2.w = v.x;
	m_rectRanking2.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking3");
	m_rectRanking3.w = v.x;
	m_rectRanking3.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking4");
	m_rectRanking4.w = v.x;
	m_rectRanking4.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking5");
	m_rectRanking5.w = v.x;
	m_rectRanking5.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking6");
	m_rectRanking6.w = v.x;
	m_rectRanking6.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking7");
	m_rectRanking7.w = v.x;
	m_rectRanking7.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking8");
	m_rectRanking8.w = v.x;
	m_rectRanking8.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking9");
	m_rectRanking9.w = v.x;
	m_rectRanking9.h = v.y;
	v = Renderer::Instance()->GetTextureSize("Ranking10");
	m_rectRanking10.w = v.x;
	m_rectRanking10.h = v.y;

	v = Renderer::Instance()->GetTextureSize("textExit");
	m_rectReturnButton.w = v.x;
	m_rectReturnButton.h = v.y;
}

//insertar nova puntuacio al map
void  Ranking::insertNewScore(map<int, string> newScores) {
	for (map<int, string>::iterator it = newScores.begin(); it != newScores.end(); ++it){
		ranking.insert(make_pair(it->first, it->second));
	}
}

SDL_Rect Ranking::getRect(int id) {
	switch (id){
	case 1:
		return rectRanking1;
		break;
	case 2:
		return m_rectRanking2;
		break;
	case 3:
		return m_rectRanking3;
		break;
	case 4:
		return m_rectRanking4;
		break;
	case 5:
		return m_rectRanking5;
		break;
	case 6:
		return m_rectRanking6;
		break;
	case 7:
		return m_rectRanking7;
		break;
	case 8:
		return m_rectRanking8;
		break;
	case 9:
		return m_rectRanking9;
		break;
	case 10:
		return m_rectRanking10;
		break;
	default:
		break;
	}
}


string Ranking::getRectID(int id) {
	switch (id){
	case 1:
		return "Ranking1";
		break;
	case 2:
		return "Ranking2";
		break;
	case 3:
		return "Ranking3";
		break;
	case 4:
		return "Ranking4";
		break;
	case 5:
		return "Ranking5";
		break;
	case 6:
		return "Ranking6";
		break;
	case 7:
		return "Ranking7";
		break;
	case 8:
		return "Ranking8";
		break;
	case 9:
		return "Ranking9";
		break;
	case 10:
		return "Ranking10";
		break;
	default:
		break;
	}
}

void  Ranking::printRanking() {
	int i = 1;
	for (map<int, string>::reverse_iterator rit = ranking.rbegin(); rit != ranking.rend(); ++rit) {
		cout << rit->second << " => " << rit->first << '\n';
		string line = to_string(i) + " - " + rit->second + " Score  " + to_string(rit->first);

		Renderer::Instance()->LoadTextureText("game_over", Text{ getRectID(i), line,Color{ 0, 0, 0, 255 },SPRITE_WIDTH * 2,SPRITE_HEIGHT });
		Vector2 v = Renderer::Instance()->GetTextureSize(getRectID(i));
		SDL_Rect r = getRect(i);
		r.w = v.x;
		r.h = v.y;
		i++;
	}

}

void  Ranking::checkMaxNumScore() {
	while (ranking.size() > maxNum)	{
		ranking.erase(prev(ranking.end()));
	}
}

//comprova si es coloca a la llista
bool Ranking::checkIfHighScore(map<int, string> newScores) {
	bool res = false;
	for (map<int, string>::iterator it = newScores.begin(); it != newScores.end(); ++it){
		map<int, string>::reverse_iterator rit = ranking.rbegin();
		if (rit->first < it->first || ranking.size() < maxNum)
		{
			ranking.insert(std::make_pair(it->first, it->second));
			res = true;
		}
	}
	return res;
}

//comprovacio de si existeix el document
bool Ranking::fileExists() {
	ifstream file(PATH_FILES + RANKING);
	return file.good();
}

//lectura del document
void Ranking::readFile() {
	ifstream file(PATH_FILES + RANKING, ios::in | std::ios::binary);
	int key;
	size_t len;
	string value;
	while (!file.eof()) {
		file.read(reinterpret_cast<char *>(&key), sizeof(key));
		file.read(reinterpret_cast<char *>(&len), sizeof(size_t));
		char* temp = new char[len + 1];
		file.read(temp, len);
		temp[len] = '\0';
		value = temp;
		delete[]temp;
		ranking.insert(std::make_pair(key, value));
	}
	file.close();
}

//escriptura en el document
void Ranking::writeFile() {
	ofstream file(PATH_FILES + RANKING, ios::out | ios::binary);

	for (map<int, string>::iterator it = ranking.begin(); it != ranking.end(); ++it){
		int key = it->first;
		string value = it->second;

		file.write(reinterpret_cast<char *>(&key), sizeof(key));
		size_t len = value.size();
		file.write(reinterpret_cast<char *>(&len), sizeof(size_t));
		file.write(value.c_str(), value.size());
	}
	file.close();
}

// us de la funcio colisio
bool Ranking::collision(SDL_Point origin, SDL_Rect target) {
	return (origin.x > target.x && origin.x < target.x + target.w && origin.y > target.y && origin.y < target.y + target.h);
}

void Ranking::EventHandle() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			sceneState = SceneState::EXIT;
			break;
		case SDL_MOUSEBUTTONDOWN:

			mousePoint = { event.motion.x, event.motion.y };

			if (collision(mousePoint, m_rectReturnButton)) {
				sceneState = SceneState::GOTO;
			}
			break;
		default:break;
		}
	}
}

void Ranking::Update() {}

void Ranking::Draw() {

	Renderer::Instance()->Clear();

	//dibuixat del ranking
	Renderer::Instance()->PushImage("ranking", rectBackground);

	Renderer::Instance()->PushImage("Ranking1", rectRanking1);
	Renderer::Instance()->PushImage("Ranking2", m_rectRanking2);
	Renderer::Instance()->PushImage("Ranking3", m_rectRanking3);
	Renderer::Instance()->PushImage("Ranking4", m_rectRanking4);
	Renderer::Instance()->PushImage("Ranking5", m_rectRanking5);
	Renderer::Instance()->PushImage("Ranking6", m_rectRanking6);
	Renderer::Instance()->PushImage("Ranking7", m_rectRanking7);
	Renderer::Instance()->PushImage("Ranking8", m_rectRanking8);
	Renderer::Instance()->PushImage("Ranking9", m_rectRanking9);
	Renderer::Instance()->PushImage("Ranking10", m_rectRanking10);
	Renderer::Instance()->PushImage("textExit", m_rectReturnButton);

	Renderer::Instance()->Render();
}

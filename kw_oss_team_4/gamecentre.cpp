#include"game.h"

using namespace std;
using namespace sf;

void game_centre(int dif) {
	int cnt = 7;
	main_story(dif);
	midres(cnt);
	cnt-=main_game_1(dif,0);
	midres(cnt);
	cnt-=main_game_2(dif,0);
	midres(cnt);
	cnt -= main_game_3(dif,0);
	midres(cnt);
	cnt -= main_game_5(dif,0);
	midres(cnt);
	cnt -= main_game_6(dif, 0);
	midres(cnt);
	cnt -= main_game_7(dif, 0);
	midres(cnt);
	//result
}
void midres(int c) {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "OSS_Team_4_main");
	window.setFramerateLimit(60);

	sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
	tbackground.loadFromFile("img/main/main.png"); // tbg�� ���ȭ�� �̹��� �ε�
	sf::Sprite background; // ��ü bg�� ����
	background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����

	sf::Font font;
	font.loadFromFile("font/BMJUA_ttf.ttf");
	sf::Text rest;
	rest.setFont(font);
	rest.setPosition(50 , 50);
	rest.setFillColor(sf::Color::White);
	rest.setCharacterSize(180);
	rest.setString("Game result");

	sf::Text res;
	
	res.setFont(font);
	res.setFillColor(sf::Color::Yellow);
	res.setCharacterSize(200);
	res.setString("o");
	for (int i = 0; i < c; i++) {
		window.draw(rest);
		for (int j = 0; j <= i; j++) {
			res.setPosition(150 * j, 200);
			window.draw(res);
		}
		window.display();
		sf::sleep(sf::seconds(0.5f));
	}
	sf::sleep(sf::seconds(3.0f));
}
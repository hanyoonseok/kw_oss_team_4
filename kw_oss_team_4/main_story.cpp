#include "game.h"
using namespace std;
using namespace sf;
void main_story(int dif) {
    sf::RenderWindow window(sf::VideoMode(1024, 768), "OSS_Team_4_story");
    window.setFramerateLimit(60); // 60fps

    sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
    tbackground.loadFromFile("img/main/story.png"); // tbg�� ���ȭ�� �̹��� �ε�
    sf::Sprite background; // ��ü bg�� ����
    background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                main(1); // ����ȭ�� â�� �ٽ� ����
            }
        }
        window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            window.close();
            break;
        }
        window.draw(background); // ���ȭ�� �׸���
        window.display(); // ǥ��
    }
}
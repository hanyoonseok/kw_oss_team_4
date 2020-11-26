#include "game.h"
using namespace std;
using namespace sf;
void main_makers()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "OSS_Team_4_makers");
    window.setFramerateLimit(60);

    sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
    tbackground.loadFromFile("img/main/maker.png"); // tbg�� ���ȭ�� �̹��� �ε�
    sf::Sprite background; // ��ü bg�� ����
    background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape || event.key.code==sf::Keyboard::Enter))) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                main(0); // ����ȭ�� â�� �ٽ� ����
            }
        }
        window.clear();
        window.draw(background); // ���ȭ�� �׸���
        window.display(); // ǥ��
    }
}
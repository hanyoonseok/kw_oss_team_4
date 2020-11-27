#define NOMINMAX
#include<Windows.h>
#include "game.h"
using namespace std;
using namespace sf;
int main(int sw)
{
    HWND hWndConsole = GetConsoleWindow();
    ShowWindow(hWndConsole, SW_HIDE);
    cout << sw << endl;
    if (sw == 1) {
        musicstart();
    }
    sf::RenderWindow window(sf::VideoMode(1024, 768), "OSS_Team_4_main");
    window.setFramerateLimit(60); // 60fps

    sf::Texture tman; // �ؽ��ĸ� ���� tman ����
    tman.loadFromFile("img/main/select.png"); // tman�� �̹��� �ε�
    sf::Sprite man; // ��ü man�� ����
    man.setTexture(tman); // ��ü man�� �̹����� tman�� �̹����� ����

    sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
    tbackground.loadFromFile("img/main/main.png"); // tbg�� ���ȭ�� �̹��� �ε�
    sf::Sprite background; // ��ü bg�� ����
    background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����

    double cnt = 0;
    int mouseX = 0; //���콺 ��Ŭ�� x��ǥ
    int mouseY = 0; //���콺 ��Ŭ�� y��ǥ

    man.setPosition(358, 418); // ���� �� ĳ���� ��ǥ ����
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                return 0;
            }
        }
        window.clear();

        sf::Vector2f speed = { 0,0 }; // �ӵ� �ʱ�ȭ

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { sf::sleep(sf::seconds(0.1f)); speed.y = 102.0f; } // �Ʒ� ����Ű
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { sf::sleep(sf::seconds(0.1f)); speed.y = -102.0f; } // �� ����Ű

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            switch ((int)man.getPosition().y) {
            case 418: //���ӽ���
                window.close();
                main_difficulty();
                break;
            case 520: //������
                window.close();
                main_makers();
                // ���� �� ����
                break;
            case 622: //������
                window.close();
                return 0;
                break;
            }
        }

        man.setPosition(man.getPosition()+speed); // ĳ���� ��ǥ ����
        window.draw(background); // ���ȭ�� �׸���

        if (man.getPosition().y < 418) { // ���� ������ �ʰ�
            man.setPosition(man.getPosition().x, 418);
        }
        else if (man.getPosition().y > 622) { // �Ʒ��� ������ �ʰ�
            man.setPosition(man.getPosition().x, 622);
        }
        window.draw(man); // ĳ���� �׸���

        window.display(); // ǥ��
    }
    return 0;
}
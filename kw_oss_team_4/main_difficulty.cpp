#include "game.h"

using namespace std;
using namespace sf;
void main_difficulty()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "OSS_Team_4_diffi");
    window.setFramerateLimit(60); // 60fps

    sf::Texture tman; // �ؽ��ĸ� ���� tman ����
    tman.loadFromFile("img/main/select.png"); // tman�� �̹��� �ε�
    sf::Sprite man; // ��ü man�� ����
    man.setTexture(tman); // ��ü man�� �̹����� tman�� �̹����� ����

    sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
    tbackground.loadFromFile("img/main/diffi.png"); // tbg�� ���ȭ�� �̹��� �ε�
    sf::Sprite background; // ��ü bg�� ����
    background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����

    double cnt = 0;
    int sw = 0;
    int mouseX = 0; //���콺 ��Ŭ�� x��ǥ
    int mouseY = 0; //���콺 ��Ŭ�� y��ǥ

    man.setPosition(358, 418); // ���� �� ĳ���� ��ǥ ����

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                main(0); // ����ȭ�� â�� �ٽ� ����
            }
        }
        window.clear();
        sf::Vector2f speed = { 0,0 }; // �ӵ� �ʱ�ȭ

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { sf::sleep(sf::seconds(0.2f)); speed.y = 102.0f; } // �Ʒ�
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { sf::sleep(sf::seconds(0.2f)); speed.y = -102.0f; } // ��
        if(window.isOpen()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                switch ((int)man.getPosition().y) {
                case 419:
                    window.close();
                    selectmode(1);
                    //game_centre(1);
                    //main_game_1(1);
                    //game(1);
                    break;
                case 521:
                    //musicstop();
                    window.close();
                    selectmode(2);
                    //game_centre(2);
                    //game(2);
                    break;
                case 623:
                    //musicstop();
                    window.close();
                    selectmode(3);
                    //game_centre(3);
                    //game(3);
                    break;
                }
            }
        }
        man.setPosition(man.getPosition() + speed); // ĳ���� ��ǥ ����
        window.draw(background); // ���ȭ�� �׸���

        if (man.getPosition().y < 419) { // ���� ������ �ʰ�
            man.setPosition(man.getPosition().x, 419);
        }
        else if (man.getPosition().y > 623) { // �Ʒ��� ������ �ʰ�
            man.setPosition(man.getPosition().x, 623);
        }
        window.draw(man); // ĳ���� �׸���

        window.display(); // ǥ��

        double x = man.getPosition().x; // ��ǥ Ȯ���� ���� �ܼ�â ���
        double y = man.getPosition().y;
        cout << x << endl;
        cout << y << endl << endl;
    }
    //return 0;
}
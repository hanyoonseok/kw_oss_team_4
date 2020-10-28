#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    window.setFramerateLimit(60); // 60fps

    sf::Texture tman; // �ؽ��ĸ� ���� tman ����
    tman.loadFromFile("img/man.png"); // tman�� �̹��� �ε�
    sf::Sprite man; // ��ü man�� ����
    man.setTexture(tman); // ��ü man�� �̹����� tman�� �̹����� ����

    sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
    tbackground.loadFromFile("img/hill.jpg"); // tbg�� ���ȭ�� �̹��� �ε�
    sf::Sprite background; // ��ü bg�� ����
    background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����


    double cnt = 0;
    int sw = 0;

    man.setPosition(512, 384); // ���� �� ĳ���� ��ǥ ����
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        sf::Vector2f speed = { 0,0 }; // �ӵ� �ʱ�ȭ

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { speed.x = 8.0f;} // D
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { speed.x = -8.0f; } // A
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { speed.y = 8.0f; } // S
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { speed.y = -8.0f; } // W

        man.setPosition(man.getPosition() + speed); // ĳ���� ��ǥ ����
        window.draw(background); // ���ȭ�� �׸���
        
        if (man.getPosition().x < 0) { // ���� ������ ������ �ʰ�
            man.setPosition(0, man.getPosition().y);
        }
        else if (man.getPosition().x > 924) { // ������ ������ ������ �ʰ�
            man.setPosition(924, man.getPosition().y);
        }
        if (man.getPosition().y < 0) { // ���� ������ �ʰ�
            man.setPosition(man.getPosition().x, 0);
        }
        else if (man.getPosition().y > 668) { // �Ʒ��� ������ �ʰ�
            man.setPosition(man.getPosition().x, 668);
        }

        // Ư�� ��ǥ 1�� ��� game_1���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_1�� �̵��Ѵ�.

        // Ư�� ��ǥ 2�� ��� game_2���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_2�� �̵��Ѵ�.

        // Ư�� ��ǥ 3�� ��� game_3���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_3�� �̵��Ѵ�.

        // Ư�� ��ǥ 4�� ��� game_4���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_4�� �̵��Ѵ�.


        man.rotate(10); // �׽�Ʈ�� ���� ��������Ʈ ȸ��

        window.draw(man); // ĳ���� �׸���

        window.display(); // ǥ��

        double x = man.getPosition().x; // ��ǥ Ȯ���� ���� �ܼ�â ���
        double y = man.getPosition().y;
        cout << x << endl;
        cout << y << endl << endl;
    }

    return 0;
}
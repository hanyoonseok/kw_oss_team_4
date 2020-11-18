#include "game.h"

using namespace std;
using namespace sf;
void main_difficulty()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "OSS_Team_4");
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

    man.setPosition(358, 384); // ���� �� ĳ���� ��ǥ ����
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                main(0); // ����ȭ�� â�� �ٽ� ����
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) //���콺 ��Ŭ�� �̺�Ʈ
                {
                    Vector2i pos = Mouse::getPosition(window);
                    mouseX = pos.x;
                    mouseY = pos.y;
                    cout << mouseX << endl;
                    cout << mouseY << endl;
                }
            }
        }
        window.clear();

        sf::Vector2f speed = { 0,0 }; // �ӵ� �ʱ�ȭ

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { speed.x = 8.0f; } // D
        //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { speed.x = -8.0f; } // A

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { speed.y = 8.0f; } // S
        //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { speed.y = -8.0f; } // W

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { sf::sleep(sf::seconds(0.1f)); speed.y = 102.0f; } // �Ʒ�
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { sf::sleep(sf::seconds(0.1f)); speed.y = -102.0f; } // ��

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            switch ((int)man.getPosition().y) {
            case 418:
                musicstop();
                window.close();
                game_centre(1);
                //main_game_1(1);
                //game(1);
                break;
            case 520:
                musicstop();
                window.close();
                game_centre(2);
                // ���� �� ����
                //game(2);
                break;
            case 622:
                musicstop();
                window.close();
                game_centre(3);
                //game(3);
                break;
            }
        }

        man.setPosition(man.getPosition() + speed); // ĳ���� ��ǥ ����
        window.draw(background); // ���ȭ�� �׸���

        if (man.getPosition().y < 418) { // ���� ������ �ʰ�
            man.setPosition(man.getPosition().x, 418);
        }
        else if (man.getPosition().y > 622) { // �Ʒ��� ������ �ʰ�
            man.setPosition(man.getPosition().x, 622);
        }
        window.draw(man); // ĳ���� �׸���

        window.display(); // ǥ��

        double x = man.getPosition().x; // ��ǥ Ȯ���� ���� �ܼ�â ���
        double y = man.getPosition().y;
        cout << x << endl;
        cout << y << endl << endl;
    }
        // Ư�� ��ǥ 1�� ��� game_1���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_1�� �̵��Ѵ�.

        // Ư�� ��ǥ 2�� ��� game_2���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_2�� �̵��Ѵ�.
        /*
        if (man.getPosition().x == 0 && man.getPosition().y == 668) { // ����ã�� ����(���ϴ�)
            window.close(); // ����ȭ�� �ݰ�
            main_game_3(); // ����ã�� ����
            // ����ã�� ���� �� ����ȭ�� ����
        }
        else if (man.getPosition().x == 0 && man.getPosition().y == 0) { // arkanoid���� (�»��)
            window.close(); // ����ȭ�� �ݰ�
            main_game_1(); // ����ã�� ����
            // ����ã�� ���� �� ����ȭ�� ����
        }
        */
        // Ư�� ��ǥ 3�� ��� game_3���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_3�� �̵��Ѵ�.

        // Ư�� ��ǥ 4�� ��� game_4���� �̵��ϰڳĴ� �޽����� ����.
        // �̵�(YES)�� ���, game_4�� �̵��Ѵ�.

    //return 0;
}
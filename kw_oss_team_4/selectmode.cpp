#include"game.h"
using namespace std;
using namespace sf;

void selectmode(int dif) {
    sf::RenderWindow window(sf::VideoMode(400, 200), "OSS_Team_4_select_mode");
    window.setFramerateLimit(60); // 60fps

    sf::Texture tman; // �ؽ��ĸ� ���� tman ����
    tman.loadFromFile("img/main/select_bl.png"); // tman�� �̹��� �ε�
    sf::Sprite man; // ��ü man�� ����
    man.setTexture(tman); // ��ü man�� �̹����� tman�� �̹����� ����

    sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
    tbackground.loadFromFile("img/main/selectmode.png"); // tbg�� ���ȭ�� �̹��� �ε�
    sf::Sprite background; // ��ü bg�� ����
    background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����

    double cnt = 0;
    int mouseX = 0; //���콺 ��Ŭ�� x��ǥ
    int mouseY = 0; //���콺 ��Ŭ�� y��ǥ

    man.setPosition(100, 45); // ���� �� ĳ���� ��ǥ ����
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                main_difficulty();
                //main(0); // ����ȭ�� â�� �ٽ� ����
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { sf::sleep(sf::seconds(0.2f)); speed.y = 60.0f; } // �Ʒ� ����Ű
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { sf::sleep(sf::seconds(0.2f)); speed.y = -60.0f; } // �� ����Ű
        if (window.isOpen()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                switch ((int)man.getPosition().y) {
                case 45: // �����ϱ�. ���������� �̵� ��, ���ϴ� ������ �����Ѵ�.
                    musicstop();
                    window.close();
                    practice(dif);
                    //game_centre(dif);
                    break;
                case 105: // �����ϱ�. ���� �ϳ��� �÷��� ��, ��ũ ���� ����� ����ϰ� �ȴ�.
                    musicstop();
                    window.close();
                    game_centre(dif);
                    //window.close();
                    // ���� �� ����
                    break;
                }
            }
        }

        man.setPosition(man.getPosition() + speed); // ĳ���� ��ǥ ����
        window.draw(background); // ���ȭ�� �׸���

        if (man.getPosition().y < 40) { // ���� ������ �ʰ�
            man.setPosition(man.getPosition().x, 45);
        }
        else if (man.getPosition().y > 110) { // �Ʒ��� ������ �ʰ�
            man.setPosition(man.getPosition().x, 105);
        }
        window.draw(man); // ĳ���� �׸���

        window.display(); // ǥ��

        double x = man.getPosition().x; // ��ǥ Ȯ���� ���� �ܼ�â ���
        double y = man.getPosition().y;
        cout << x << endl;
        cout << y << endl << endl;
    }
}
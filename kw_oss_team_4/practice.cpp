#include"game.h"
using namespace std;
using namespace sf;
void practice(int dif) {
    pmusicstart();
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Practice");
    window.setFramerateLimit(60); // 60fps

    sf::Texture tman; // �ؽ��ĸ� ���� tman ����
    tman.loadFromFile("img/main/softman.png"); // tman�� �̹��� �ε�
    sf::Sprite man; // ��ü man�� ����
    man.setTexture(tman); // ��ü man�� �̹����� tman�� �̹����� ����

    sf::Texture tsaebit; // �ؽ��ĸ� ���� tman ����
    tsaebit.loadFromFile("img/main/saebit.jpg"); // tman�� �̹��� �ε�
    sf::Sprite saebit; // ��ü man�� ����
    saebit.setTexture(tsaebit); // ��ü man�� �̹����� tman�� �̹����� ����

    sf::Texture tbackground; // ���ȭ���� ���� tbg �༺
    tbackground.loadFromFile("img/main/practicemap.png"); // tbg�� ���ȭ�� �̹��� �ε�
    sf::Sprite background; // ��ü bg�� ����
    background.setTexture(tbackground); // ��ü bg�� �̹����� ���ȭ�� �̹����� tbg�� ����

    double cnt = 0;
    int mouseX = 0; //���콺 ��Ŭ�� x��ǥ
    int mouseY = 0; //���콺 ��Ŭ�� y��ǥ

    man.setPosition(358, 320); // ���� �� ĳ���� ��ǥ ����
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                pmusicstop();
                window.close(); // ����â �ݰ�
                musicstart();
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {speed.y = 8.0f; } //��
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {speed.y = -8.0f; } //��
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {speed.x = -8.0f; } //��
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {speed.x = 8.0f; } //��

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (man.getPosition().x >= 360 && man.getPosition().x <= 608 && man.getPosition().y >= 312 && man.getPosition().y <= 432) { // ħ�� -> �ڷΰ���
                pmusicstop();
                window.close();
                musicstart();
                main_difficulty();
            }
            switch ((int)man.getPosition().y) {
            case 418:
                //window.close();
                //main_difficulty();
                break;
            case 520:
                //window.close();
                // ���� �� ����
                break;
            case 622:
                //window.close();
                break;
            }
        }

        man.setPosition(man.getPosition() + speed); // ĳ���� ��ǥ ����
        window.draw(background); // ���ȭ�� �׸���

        if (man.getPosition().x < 0) { // ���� ������ �ʰ�
            man.setPosition(0, man.getPosition().y);
        }
        else if (man.getPosition().x > 955) { // �Ʒ��� ������ �ʰ�
            man.setPosition(955, man.getPosition().y);
        }

        if (man.getPosition().y < 0) { // ���� ������ �ʰ�
            man.setPosition(man.getPosition().x, 0);
        }
        else if (man.getPosition().y > 678) { // �Ʒ��� ������ �ʰ�
            man.setPosition(man.getPosition().x, 678);
        }
        window.draw(man); // ĳ���� �׸���

        window.display(); // ǥ��

        double x = man.getPosition().x; // ��ǥ Ȯ���� ���� �ܼ�â ���
        double y = man.getPosition().y;
        cout << x << endl;
        cout << y << endl << endl;
    }

}
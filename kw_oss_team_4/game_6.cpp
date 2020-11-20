#include "game.h"

using namespace std;
using namespace sf;


void main_game_6(int dif, int pr) // ���̵��� ��Ÿ���� dif. 1 : easy, 2 : normal, 3 : hard
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "dodge");
    window.setFramerateLimit(60); // 60fps

    Texture txBackground;
    txBackground.loadFromFile("img/man.png");
    Sprite spBackground;
    spBackground.setTexture(txBackground);
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if (event.KeyPressed == sf::Keyboard::Escape) {
                    window.close();
                    main(1);
                }
            }
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close();
                if (pr == 1) {
                    practice(dif);
                }
                else {
                    main(1); // ����ȭ�� â�� �ٽ� ����
                }
            }
        }

        
        if (Keyboard::isKeyPressed(Keyboard::Right)) //����Ű ��
        {
            
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)) //����Ű ��
        {
            
        }

        window.draw(spBackground);
        window.display(); // ǥ��

        
    }
}
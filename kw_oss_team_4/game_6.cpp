#include "game.h"
#include <time.h>

using namespace std;
using namespace sf;

struct Enemy
{
    bool isHit = false;
    Sprite spEnemy;
    Vector2f speed = { 8,8 };
};
int i = 0;
int main_game_6(int dif, int pr) // ���̵��� ��Ÿ���� dif. 1 : easy, 2 : normal, 3 : hard
{
    sf::RenderWindow window(sf::VideoMode(1024, 678), "dodge");
    window.setFramerateLimit(60); // 60fps

    Texture txBackground, txPlayer, txEnemy;
    txBackground.loadFromFile("img/game6/background.png");
    txPlayer.loadFromFile("img/game6/poland.png");
    txEnemy.loadFromFile("img/game6/enemy.png");

    Enemy enemy[300];
    Sprite spBackground,spPlayer;
    spBackground.setTexture(txBackground);
    spPlayer.setTexture(txPlayer);

    for(int i=0; i<300; i++)
    enemy[i].spEnemy.setTexture(txEnemy);
    

    spPlayer.setPosition(512, 384);

    Clock clock;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close();
                if (pr == 1) {
                    practice(dif);
                }
                else {
                    musicstart();
                    main_difficulty();
                }
            }
        }

        Vector2f speed = { 0,0 }; // �ӵ� �ʱ�ȭ
        Time elapsed = clock.getElapsedTime(); //���� restart() ���� �ɸ� �ð�

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { speed.y = 8.0f; } //��
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { speed.y = -8.0f; } //��
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { speed.x = -8.0f; } //��
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { speed.x = 8.0f; } //��
        spPlayer.setPosition(spPlayer.getPosition() + speed); // ĳ���� ��ǥ ����

        if (spPlayer.getPosition().x < 0) { // �������� ������ �ʰ�
            spPlayer.setPosition(0, spPlayer.getPosition().y);
        }
        else if (spPlayer.getPosition().x > 990) { // ���������� ������ �ʰ�
            spPlayer.setPosition(990, spPlayer.getPosition().y);
        }

        if (spPlayer.getPosition().y < 0) { // ���� ������ �ʰ�
            spPlayer.setPosition(spPlayer.getPosition().x, 0);
        }
        else if (spPlayer.getPosition().y > 648) { // �Ʒ��� ������ �ʰ�
            spPlayer.setPosition(spPlayer.getPosition().x, 648);
        }
        
        
        
        window.draw(spBackground);
        window.draw(spPlayer);

        if (elapsed.asSeconds() >= 0.3) //0.3�ʸ��� �߻� �̺�Ʈ
        {
            enemy[i].spEnemy.setPosition(enemy[i].spEnemy.getPosition() + enemy[i].speed);
            window.draw(enemy[i].spEnemy);
            i++;
            clock.restart(); //Ÿ�̸� �����
        }
        if (i == 300)
            i = 0;
        window.display(); // ǥ��
    }
    return 0;
}
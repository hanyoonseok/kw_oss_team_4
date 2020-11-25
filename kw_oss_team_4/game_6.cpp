#include "game.h"
#include <time.h>
#include <random>
using namespace std;
using namespace sf;

struct Enemy
{
    Sprite spEnemy;
    FloatRect enemyRect;
    Vector2f speed = { 0,0 };
};

int main_game_6(int dif, int pr) // ���̵��� ��Ÿ���� dif. 1 : easy, 2 : normal, 3 : hard
{
    sf::RenderWindow window(sf::VideoMode(1024, 678), "dodge");
    window.setFramerateLimit(60); // 60fps

    //font & text
    Font font;
    font.loadFromFile("img/game6/arial.ttf");
    Text timeTxt;
    timeTxt.setFont(font);
    timeTxt.setCharacterSize(50);
    timeTxt.setFillColor(Color::Red);
    timeTxt.setStyle(Text::Bold);

    sf::Texture tgtext;
    tgtext.loadFromFile("img/main/g6.png");
    sf::Sprite gtext;
    gtext.setTexture(tgtext);
    window.draw(gtext);
    window.display();
    sf::sleep(sf::seconds(2.0f));

    int difficulty;
    switch (dif) //���̵��� ���� �� ���� 
    {
    case 1:difficulty = 100; break;
    case 2:difficulty = 150; break;
    case 3:difficulty = 200; break;
    }

    //texture
    Texture txBackground, txPlayer, txEnemy, txShield;
    txBackground.loadFromFile("img/game6/background.png");
    txPlayer.loadFromFile("img/game6/player.png");
    txEnemy.loadFromFile("img/game6/enemy.png");
    txShield.loadFromFile("img/game6/shield.png");

    //sprite
    Enemy* enemy = new Enemy[difficulty];
    Sprite spBackground,spPlayer, spShield;
    spBackground.setTexture(txBackground);
    spPlayer.setTexture(txPlayer);
    spShield.setTexture(txShield);

    //set random
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis1(0, 1023); //������ �� ������ġ
    uniform_int_distribution<int> dis2(0, 677);
    uniform_int_distribution<int> dis3(-4, 4); //�������ӵ�
    uniform_int_distribution<int> dis4(-4, 4); // ""
    
    //srand((unsigned int)time(NULL));
    int* rand1 = new int[difficulty];
    int* rand2 = new int[difficulty];
    int* randspd1 = new int[difficulty];
    int* randspd2 = new int[difficulty];
    for (int i = 0; i < difficulty; i++)
    {
        rand1[i] = dis1(gen);
        rand2[i] = dis2(gen);
        randspd1[i] = dis3(gen);
        randspd2[i] = dis4(gen);
    }
    for (int i = 0; i < difficulty; i++)
    {
        enemy[i].spEnemy.setTexture(txEnemy);
        enemy[i].spEnemy.setPosition(rand1[i], rand2[i]);
        enemy[i].speed = Vector2f(randspd1[i], randspd2[i]);
        enemy[i].enemyRect = enemy[i].spEnemy.getGlobalBounds();
    }

    //setposition
    spPlayer.setPosition(512, 384);
    spShield.setPosition(420, 300);
    timeTxt.setPosition(460, 0);
    Clock clock, clock1;
    
    while (window.isOpen())
    {
        sf::Event event;
        FloatRect playerRect = spPlayer.getGlobalBounds();
        FloatRect shieldRect = spShield.getGlobalBounds();
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
        Time TimeLimit = clock1.getElapsedTime();

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
        window.draw(spShield);
        for (int i = 0; i < difficulty; i++)
        {
            if (!shieldRect.contains(spPlayer.getPosition()))
            {
                if (playerRect.contains(enemy[i].spEnemy.getPosition())) //�浹���� �� �й� �̺�Ʈ
                {
                    failsound();
                    sf::sleep(sf::seconds(1.5f));
                    window.close();
                    if (pr == 1) {
                        practice(dif);
                    }
                    return 1;
                    break;
                    cout << "lose " << endl;
                }
            }
            enemy[i].spEnemy.setPosition(enemy[i].spEnemy.getPosition() + enemy[i].speed);
            if (enemy[i].spEnemy.getPosition().x <= 0 || enemy[i].spEnemy.getPosition().x >= 1023)
                enemy[i].speed.x = -enemy[i].speed.x;
            if(enemy[i].spEnemy.getPosition().y <= 0 || enemy[i].spEnemy.getPosition().x >= 677)
                enemy[i].speed.y = -enemy[i].speed.y;

            window.draw(enemy[i].spEnemy);
        }
        if (elapsed.asSeconds() >= 2) //0.3�ʸ��� �߻� �̺�Ʈ
        {
            spShield.setPosition(dis1(gen), dis2(gen)); //���� ��ġ ����
            clock.restart(); //Ÿ�̸� �����
        }
        string s = to_string(10-TimeLimit.asSeconds());

        timeTxt.setString(s);
        window.draw(timeTxt);
        window.display(); // ǥ��

        if (stod(s) <= 0.0) //�̼� ���� �̺�Ʈ
        {
            failsound();
            sf::sleep(sf::seconds(1.5f));
            window.close();
            if (pr == 1) {
                practice(dif);
            }
            return 1;
            break;
        }
    }
    return 0;
}
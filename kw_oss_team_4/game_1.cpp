#include<iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;
using namespace sf;

void main_game_1()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Arkanoid");
    window.setFramerateLimit(60); // 60fps

    sf::Texture txBack, txPlayer, txTile, txBall; // 
    txBack.loadFromFile("img/game1/background.jpg"); // 
    txPlayer.loadFromFile("img/game1/paddle.png"); // 
    txBall.loadFromFile("img/game1/ball.png");
    txTile.loadFromFile("img/game1/block01.png");

    sf::Sprite spBack, spPlayer, spBall; // 
    Sprite spTile[40];
    spBack.setTexture(txBack); //
    spPlayer.setTexture(txPlayer);
    spBall.setTexture(txBall);
    for (int i = 0; i < 40; i++)
    {
        spTile[i].setTexture(txTile);
        spTile[i].setPosition((float)250 + (i % 8) * 60, (float)120 + (i / 8) * 30);
    }

    spPlayer.setPosition(300, 700);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if (event.KeyPressed == sf::Keyboard::Escape) {
                    window.close();
                    main();
                }
                if (Keyboard::isKeyPressed(Keyboard::Right)) 
                {
                    spPlayer.setPosition(spPlayer.getPosition().x + 15, 700);
                }
                else if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    spPlayer.setPosition(spPlayer.getPosition().x - 15, 700);
                }
                
            }
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                main(); // ����ȭ�� â�� �ٽ� ����
            }
        }
        
        window.draw(spBack); // ���
        window.draw(spBall);
        for (int i = 0; i < 40; i++)
            window.draw(spTile[i]); //Ÿ��
        window.draw(spPlayer);//�÷��̾�
        window.display(); // ǥ��
    }
}

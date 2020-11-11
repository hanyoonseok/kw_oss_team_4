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
    FloatRect TileRect[40];

    spBack.setTexture(txBack); //
    spPlayer.setTexture(txPlayer);
    spBall.setTexture(txBall);

    float ballX = 300;
    float ballY = 300;
    float powerX = 5;
    float powerY = 5;
    int powerDir = 1; //-1 : left, 0 : ��������, 1 : right

    for (int i = 0; i < 40; i++)
    {
        spTile[i].setTexture(txTile);
        spTile[i].setPosition((float)250 + (i % 8) * 60, (float)120 + (i / 8) * 30);
        TileRect[i] = spTile[i].getGlobalBounds(); //Ÿ�� ��� ����
    }

    spPlayer.setPosition(300, 700);

    while (window.isOpen())
    {
        sf::Event event;
        FloatRect playerRect = spPlayer.getGlobalBounds();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                if (event.KeyPressed == sf::Keyboard::Escape) {
                    window.close();
                    main();
                }
            }
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) { // ��ũ���� X��ư�� �����ų�, Ȥ�� Ű������ ESC�� ������ ����ȭ������ ���ư����� ����
                window.close(); // ����â �ݰ�
                main(); // ����ȭ�� â�� �ٽ� ����
            }
        }
        if (ballX <= 0 || ballX >= 1024) //���� ������ ������ ������ �ʰ�
            powerX = -powerX;
        if (ballY <= 0 || ballY >= 768)
            powerY = -powerY;
        powerDir = 0;
        if (Keyboard::isKeyPressed(Keyboard::Right)) //����Ű ��
        {
            spPlayer.setPosition(spPlayer.getPosition().x + 8, 700);
            powerDir = 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)) //����Ű ��
        {
            spPlayer.setPosition(spPlayer.getPosition().x - 8, 700);
            powerDir = -1;
        }
        

        ballY += powerY; //���� �������� ����
        ballX += powerX;
        spBall.setPosition(ballX, ballY);

        if (playerRect.contains(spBall.getPosition())) //���� �÷��̾� �浹�ϸ�
        {
            powerY = -powerY;
            float temp = spBall.getPosition().x - spPlayer.getPosition().x;
            powerX += temp / 100;
            powerY += temp / 100;

            if (powerDir==1 && powerX <= 0)
                powerX = -powerX;
            else if (powerDir==-1 && powerX >= 0)
                powerX = -powerX;
        }

        for(int i=0; i<40; i++)
        {
            if (TileRect[i].contains(spBall.getPosition())) //���� Ÿ�� �浹�ϸ�
            {
                spTile[i].setPosition(-100, 0);
                TileRect[i] = spTile[i].getGlobalBounds();
                powerY = -powerY;
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

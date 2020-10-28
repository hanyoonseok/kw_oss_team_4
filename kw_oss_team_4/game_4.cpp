#include<iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

struct TileInfo
{
    bool isMine = false; // false�̸� �Ϲ�Ÿ��/����Ÿ�� , true�̸� ����Ÿ��
    bool isSelected = false; //true�̸� ������ Ÿ��
    int num = 0;
};

struct TileInfo tileInfo[16][16];

void setMine() //Ÿ�Ͽ� ���� ����
{
    //���� ����
    srand((unsigned int)time(NULL));
    int rand1[40];
    int rand2[40];

    //������ Ÿ�Ͽ� ���� ����
    for (int i = 0; i < 40; i++)
    {
        rand1[i] = rand() % 16;
        rand2[i] = rand() % 16;
        for (int j = 0; j < i; j++)
        {
            if (rand1[j] == rand1[i] && rand2[j] == rand2[i]) //�ߺ� ����
            {
                i--;
                break;
            }
        }
    }

    for (int i = 0; i < 40; i++)
    {
        tileInfo[rand1[i]][rand2[i]].isMine = true;
    }
}

void setNumber() // ���� �ֺ� Ÿ�Ͽ� ���� ����
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (tileInfo[i][j].isMine == true) //���� Ÿ�� �ֺ� Ÿ�ϵ��� num�� 1�� ����
            {
                if (i == 0) // [0,j]
                {
                    if (j == 0) // [0,0]
                    {
                        tileInfo[0][1].num++;
                        tileInfo[1][0].num++;
                        tileInfo[1][1].num++;
                    }
                    else if (j == 15) //[0,15]
                    {
                        tileInfo[1][15].num++;
                        tileInfo[1][14].num++;
                        tileInfo[0][14].num++;
                    }
                    else if (j > 0 && j < 15) // [0, 1~14]
                    {
                        tileInfo[i][j - 1].num++;
                        tileInfo[i + 1][j - 1].num++;
                        tileInfo[i + 1][j].num++;
                        tileInfo[i + 1][j + 1].num++;
                        tileInfo[i][j + 1].num++;
                    }
                }
                else if (i == 15) // [15, y]
                {
                    if (j == 0) // [15,0]
                    {
                        tileInfo[14][0].num++;
                        tileInfo[14][1].num++;
                        tileInfo[15][1].num++;
                    }
                    else if (j == 15)
                    {
                        tileInfo[14][15].num++;
                        tileInfo[14][14].num++;
                        tileInfo[15][14].num++;
                    }
                }
            }
            else if (i > 0 && i < 15) // [1~14, j]
            {
                if (j == 0) // [1~14, 0]
                {
                    tileInfo[i - 1][j].num++;
                    tileInfo[i - 1][j + 1].num++;
                    tileInfo[i][j + 1].num++;
                    tileInfo[i + 1][j + 1].num++;
                    tileInfo[i + 1][j].num++;
                }
                else if (j == 15) //[1~14, 15]
                {
                    tileInfo[i - 1][j].num++;
                    tileInfo[i - 1][j - 1].num++;
                    tileInfo[i][j - 1].num++;
                    tileInfo[i + 1][j - 1].num++;
                    tileInfo[i + 1][j].num++;
                }
                else if (j > 0 && j < 15)
                {
                    tileInfo[i - 1][j].num++;
                    tileInfo[i - 1][j - 1].num++;
                    tileInfo[i][j - 1].num++;
                    tileInfo[i + 1][j - 1].num++;
                    tileInfo[i + 1][j].num++;
                    tileInfo[i + 1][j + 1].num++;
                    tileInfo[i][j + 1].num++;
                    tileInfo[i - 1][j + 1].num++;
                }
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "MineSweeper");
    window.setFramerateLimit(60); // 60fps

    sf::Texture tsmile; // ������ ��ũ
    tsmile.loadFromFile("img/smile.png"); // tman�� �̹��� �ε�
    sf::Sprite smile; // ��ü man�� ����
    smile.setTexture(tsmile); // ��ü man�� �̹����� tman�� �̹����� ����

    Texture tTile[16][16]; // �� Ÿ��

    Sprite Tile[16][16]; //16 x 16 ������

    int FlagNum = 0; // ��Ŭ������ üũ�� �÷��� ����
    int SelectedTileNum = 0; //������ Ÿ�� ����
    int mouseX = 0; //Ŭ���� ���콺 x��ǥ
    int mouseY = 0; //Ŭ���� ���콺 y��ǥ

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            tTile[i][j].loadFromFile("img/tile.png"); // �� Ÿ�� �ε�
            Tile[i][j].setTexture(tTile[i][j]);
            Tile[i][j].setPosition((float)200 + 40 * i, (float)100 + 40 * j);
        }
    }

    setMine();
    setNumber();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) //���콺 ��Ŭ�� �̺�Ʈ
                {
                    Vector2i pos = Mouse::getPosition(window);
                    mouseX = pos.x;
                    mouseY = pos.y;

                }
            }
        }

        window.clear();
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                window.draw(Tile[i][j]); // Ÿ�� �׸���
            }
        }

        smile.setPosition(500, 30); // ������ ��ġ ����
        window.draw(smile); // ������ �׸���

        window.display(); // ǥ��
    }

    return 0;
}

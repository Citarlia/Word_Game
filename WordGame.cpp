#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "WordGame.h"
#include "utils.h"
#include "common.h"

void WordGame::init()
{
	for (size_t i = 0; i < COL; i++)
	{
		for (size_t j = 0; j < ROW; j++)
		{
			map[i][j] = 0;
		}
	}
}

WordGame::WordGame()
{
	init();
}

void WordGame::load(int level)
{
	std::ifstream f("1.wor");
	if (!f.is_open())
	{
		std::cout << "关卡加载失败！";
		exit(1);
	}
	int ch;
	for (size_t i = 0; i < COL; i++)
	{
		for (size_t j = 0; j < ROW; j++)
		{
			if (f >> ch && ch != EOF)
			{
				map[i][j] = ch;
			}
		}
	}
	Pos peoplePos = people.getPos();
	map[peoplePos.x][peoplePos.y] = 2;

	show();
}

void WordGame::play()
{
	while (true)
	{
		move();
		system("cls");
		show();
		if (map[people.getPos().y][people.getPos().x] == 3)
		{
			break;
		}
	}
	std::cout << "You win!";
	exit(0);
}

// 渲染
void WordGame::show()
{
	for (size_t i = 0; i < COL; i++)
	{
		for (size_t j = 0; j < ROW; j++)
		{
			if (map[i][j] == 0)
			{
				std::cout << "  ";
			}
			else if (map[i][j] == 1)
			{
				std::cout << "墙";
			}
			else if (map[i][j] == 2)
			{
				std::cout << "人";
			}
			else if (map[i][j] == 3)
			{
				std::cout << "门";
			}

		}
		std::cout << '\n';
	}

	// 这里是测试用的，打印实际二维数组内容
	//for (size_t i = 0; i < COL; i++)
	//{
	//	for (size_t j = 0; j < ROW; j++)
	//	{
	//		std::cout << map[i][j];
	//	}
	//	std::cout << '\n';
	//}
}

// 这里的xy坐标有点问题，之后会进行优化
void WordGame::move()
{
	char input = getInput();
	Pos curPos = people.getPos();
	if ((input == 'w' || input == 'W'))
	{
		map[curPos.y - 1][curPos.x] == 1 ? people.setPos(curPos.x, curPos.y) : people.setPos(curPos.x, curPos.y - 1);
	}
	else if ((input == 'a' || input == 'A'))
	{
		map[curPos.y][curPos.x - 1] == 1 ? people.setPos(curPos.x, curPos.y) : people.setPos(curPos.x - 1, curPos.y);
	}
	else if ((input == 's' || input == 'S'))
	{
		map[curPos.y + 1 ][curPos.x]== 1 ? people.setPos(curPos.x, curPos.y) : people.setPos(curPos.x, curPos.y + 1);
	}
	else if ((input == 'd' || input == 'D'))
	{
		map[curPos.y][curPos.x + 1] == 1 ? people.setPos(curPos.x, curPos.y) : people.setPos(curPos.x + 1, curPos.y);
	}
	update(curPos, people.getPos());
}

// 更新地图
void WordGame::update(Pos origin, Pos current)
{
	if (map[current.y][current.x] == 3)
	{
		return;
	}
	map[origin.y][origin.x] = 0;
	map[current.y][current.x] = 2;
}


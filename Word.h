#pragma once

// 这里的xy坐标有点问题，之后会进行优化
struct Pos
{
	int x;
	int y;
};

// 文字基类
class Word
{
	Pos pos;

public:
	Pos getPos();
	void setPos(int x, int y);
};


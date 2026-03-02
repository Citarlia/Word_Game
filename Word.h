#pragma once

struct Pos
{
	int x;
	int y;
};

class Word
{
	Pos pos;

public:
	Pos getPos();
	void setPos(int x, int y);
};


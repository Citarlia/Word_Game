#include "Word.h"

Pos Word::getPos()
{
	return pos;
}

void Word::setPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
}

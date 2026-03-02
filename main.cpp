#include <iostream>
#include "WordGame.h"
#include "utils.h"

int main() 
{
	WordGame game = WordGame();
	game.init();
	game.load(0); // 这里暂时写0，之后添加关卡设计后传入的整数就代表具体关卡数
	game.play();
}
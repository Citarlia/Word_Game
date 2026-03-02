#include <iostream>
#include "WordGame.h"
#include "utils.h"

int main() 
{
	WordGame game = WordGame();
	game.init();
	game.load(0);
	game.play();
}
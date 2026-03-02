#pragma once
#include "PeopleWord.h"
#include "common.h"

class WordGame
{
	int map[COL][ROW];
	PeopleWord people;

public:
	void init();
	WordGame();
	void load(int level);
	void play();
	void show();
	void move();
	void update(Pos origin, Pos current);
};


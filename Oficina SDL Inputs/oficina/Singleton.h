#pragma once
#include <SDL.h>
#include <iostream>


class Singleton
{
	int points;
	
	
public:
	Singleton();
	~Singleton();

	void AddPoints(int p);
	int GetPoints();
};


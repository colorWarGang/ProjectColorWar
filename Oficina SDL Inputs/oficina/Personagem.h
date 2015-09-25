#pragma once
#include "Singleton.h"


class Personagem
{
	SDL_Rect rect;
	float posY;
	float posX;
	float velX;
	float velY;

public:
	Personagem();
	~Personagem();

	void SetPosition(int x, int y);
	void Draw(SDL_Renderer* renderer);
	void SetColor(int vermelho, int verde, int azul);
};


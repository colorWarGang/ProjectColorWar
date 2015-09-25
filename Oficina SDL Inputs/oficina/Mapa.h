#pragma once
#include "Singleton.h"
#define TAMANHO_MATRIZ_X 128
#define TAMANHO_MATRIZ_Y 64

class Mapa
{
	SDL_Surface* surface = NULL;
	SDL_Rect fromMap, toMap;
	SDL_Texture* texture;
	int matrizTeste[TAMANHO_MATRIZ_X][TAMANHO_MATRIZ_Y];
public:
	Mapa();
	~Mapa();

	void CriaMapa(SDL_Renderer* renderer);
	void DrawMap(SDL_Renderer* renderer);
};


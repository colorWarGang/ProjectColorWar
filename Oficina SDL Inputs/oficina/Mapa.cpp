#include "Mapa.h"
#define TAMANHO_MATRIZ_X 128
#define TAMANHO_MATRIZ_Y 64
#define TAMANHO_TILE 8

Mapa::Mapa()
{
}


Mapa::~Mapa()
{
}

void Mapa::CriaMapa(SDL_Renderer* renderer)
{
	int commit1, commit2, commit3, commit4;
	surface = SDL_LoadBMP("colorwar.bmp");
	if (surface == NULL)
		std::cout << SDL_GetError();
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	//matrizTeste[2][3] = 2;
	for (int i = 0; i < TAMANHO_MATRIZ_Y; i++)
	{
		for (int j = 0; j < TAMANHO_MATRIZ_X; j++)
		{
			matrizTeste[i][j] = 2;
		}
	}
	

}

void Mapa::DrawMap(SDL_Renderer* renderer)
{
	for (int i = 0; i < TAMANHO_MATRIZ_Y; i++)
	{
		for (int j = 0; j < TAMANHO_MATRIZ_X; j++)
		{
			toMap = { j*TAMANHO_TILE, i*TAMANHO_TILE, TAMANHO_TILE, TAMANHO_TILE };
			switch (matrizTeste[i][j])
			{
			case 0:
				fromMap = { 0, 0, 16, 16 };
				break;
			case 1:
				fromMap = { 17, 0, 16, 16 };
				break;
			case 2:
				fromMap = { 40, 0, 16, 16 };
				break;
			default:
				fromMap = { 32, 0, 16, 16 };
				break;
			}
			SDL_RenderCopy(renderer, texture, &fromMap, &toMap);
		}
	}
}
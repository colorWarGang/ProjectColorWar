#include<SDL.h>
#include<iostream>
#include"Init.h"
#include "Personagem.h"
#include "Singleton.h"
#include "Mapa.h"

#define DIMENSAO_TILES 30
#define LARGURA_TELA 1024
#define ALTURA_TELA 512

SDL_Renderer* renderer = NULL;
SDL_Rect myRect = { 0, 0, 32, 32 };
bool quit = false;

SDL_Window* w_pWindow;
SDL_Renderer* m_pRenderer;

SDL_Texture* m_pTexture;
SDL_Rect m_souceRectangle;
SDL_Rect m_destinationRectangle;

float velX , velY ;
float posX=200, posY=200;
float tamX, tamY;
float velocidadeUnificada = 8;

void Init();
void Renderer();
void ProcessInput();
void Update();
void Start();

int cor = 0;

Personagem personagem1;
Personagem personagem2;
Mapa map;
double deltaTime;

int main(int argc, char** argv)
{	
	
	int fps = 60;
	int fpsMill = 1000 / fps;
	int currentFrameTime;

	Init();
	Start();

	while (!quit)
		
	{
		double startTime = SDL_GetTicks();
		currentFrameTime = SDL_GetTicks();

		ProcessInput(); // REGISTRA E PROCESSA INPUTS
		// UPDATE()  //LOGICA DE JOGO
		Update();
		Renderer();

		int pastTime = SDL_GetTicks() - currentFrameTime;
		if (fpsMill > pastTime)
			SDL_Delay(fpsMill - pastTime);

		double endTime = SDL_GetTicks();
		deltaTime = (endTime - startTime) / 1000;
	}

	return 0;
}

void Start()
{
	velX = 0;
	velY = 0;
	tamX = 32;
	tamY = 32;
	map.CriaMapa(renderer);
}
void Init()
{
	SDL_Window* window = NULL;

	window = SDL_CreateWindow(
		"An SDL2 window",                  // window title
		30,           // initial x position
		30,           // initial y position
		LARGURA_TELA,                               // width, in pixels
		ALTURA_TELA,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
		);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	SDL_Surface* pTempSurface = SDL_LoadBMP("TileMaps001.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_souceRectangle.w, &m_souceRectangle.h);

	m_destinationRectangle.x = m_souceRectangle.x = 0;
	m_destinationRectangle.y = m_souceRectangle.y = 0;
	m_destinationRectangle.w = m_souceRectangle.w;
	m_destinationRectangle.h = m_souceRectangle.h;
}

void ProcessInput()
{
	SDL_Event e;
	if (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		if (e.type == SDL_KEYDOWN)
		{
			//Set the proper message surface
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: velY -= velocidadeUnificada; break;
			case SDLK_DOWN: velY = velocidadeUnificada; break;
			case SDLK_LEFT: velX = -velocidadeUnificada; break;
			case SDLK_RIGHT: velX = velocidadeUnificada; break;
			case SDLK_t: tamX += 1; tamY += 1; break;
			case SDLK_y: tamX -= 1; tamY -= 1; break;
			case SDLK_SPACE: cor++; break;	
			}
		}
		else
		{
			velX = velocidadeUnificada;
			velY = 0;
		}
	}
}
void Update()
{
	
	posX = posX + velX; 
	posY = posY + velY;
	
	printf("ola");

	if (cor >= 3)
		cor = 0;
}
void Renderer()
{
	//limpa tela
	/*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);*/
	map.DrawMap(renderer);
	myRect = { posX, posY, tamX, tamY};

	if (cor == 0)
		SDL_SetRenderDrawColor(renderer, 255, 0,0, 255);
	else if (cor == 1)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	else if (cor == 2)
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &myRect);

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_souceRectangle, &m_destinationRectangle);

	personagem1.SetColor(255, 0, 0);
	//personagem1.Draw(renderer);
	personagem2.SetPosition(300, 100);
	
	personagem2.Draw(renderer);

	//printf("teste");
	

	SDL_RenderPresent(renderer);
}

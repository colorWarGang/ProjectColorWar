#include "Personagem.h"

//SDL_Renderer* renderer = NULL;

Personagem::Personagem()
{
	rect = { 200, 200, 50, 50 };

	std::cout << "PERSONAGEM NASCEU" ;
 }

Personagem::~Personagem()
{
}

void Personagem::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);

}
void Personagem::SetPosition(int x, int y)
{
	rect = { x, y, 50, 50 };
}

void Personagem::SetColor(int vermelho, int verde, int azul)
{
	
}

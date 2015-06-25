#include "Game.h"	
#include <iostream>
#include <SDL2/SDL.h>
Game::Game() {
	m_bRunning = true;
}	
Game::~Game() {}
void Game:: init(char* titulo ="Hola Mundo",int xpos = 0, int ypos = 0 , int alto = 100, int ancho = 100 , int banderas = 0)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		m_bRunning =  false;
	}

	m_pWindow = SDL_CreateWindow(titulo, xpos, ypos, alto, ancho, banderas);
	if (m_pWindow == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		m_bRunning =  false;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC);
	if (m_pRenderer == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		m_bRunning =  false;
	}
	bmp = SDL_LoadBMP("./hello.bmp");
	if (bmp == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		m_bRunning= false;
	}
	tex = SDL_CreateTextureFromSurface(m_pRenderer, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		m_bRunning = false;
	}
	
}
void Game:: render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, tex, NULL, NULL);
	SDL_RenderPresent(m_pRenderer);
}
void Game:: update()
{
}
void Game:: handleEvents()
{
	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			m_bRunning = false;
			break;
			default:
			break;
		}
	}
}
void Game:: clean()
{
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}
bool Game:: running()
{
	return m_bRunning;
}
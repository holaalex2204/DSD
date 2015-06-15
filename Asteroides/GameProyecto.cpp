#include "GameProyecto.h"	
#include <iostream>
#include "Asteroide.h"
#include "Coordenada.h"
#include <SDL2/SDL.h>
#include <time.h>
#include "Vector2D.h"
GameProyecto::GameProyecto() {
	m_bRunning = true;
}	
GameProyecto::~GameProyecto() {}
void GameProyecto:: init(char* titulo ="Hola Mundo",int xpos = 0, int ypos = 0 , int alto = 100, int ancho = 100 , int banderas = 0, int cantAsteroides=100
)
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
	for(int i = 0 ; i<cantAsteroides ; i++)
	{
		srand (i);
		int lados = (rand()%10 + rand()%15)%10 + 10;
		long double radio  = rand()%15 + rand()%25 +10;
		asteroides.push_back(Asteroide(lados,radio));
		asteroides.back().posicionaCentro(Coordenada((rand()%600),rand()%800));
	}
}
void GameProyecto:: render()
{
	SDL_Point p1,p2;
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);	
	for(int  i=0; i < asteroides.size(); i++) {
		Coordenada centro = asteroides[i].obtenCentro();
		SDL_SetRenderDrawColor(m_pRenderer, rand()%255, rand()%255, rand()%255, 255);
		vector<Coordenada> vertices = asteroides[i].obtenVertices();
		p1.x = vertices.back().obtenerX();
		p1.y = vertices.back().obtenerY();
		for(int j = 0; j<vertices.size(); j++)
		{
			p2.x = vertices[j].obtenerX();
			p2.y = vertices[j].obtenerY();
			SDL_Point points[4] = { p1, p2};
			SDL_RenderDrawLines(m_pRenderer, points, 2);
			p1 = p2;
		}
	}
	SDL_RenderPresent(m_pRenderer);
}
void GameProyecto:: update()
{
	for(int  i=0; i < asteroides.size(); i++) {
		Coordenada centro = asteroides[i].obtenCentro();
		if((centro.obtenerX()>650 || centro.obtenerX() <-50) || (centro.obtenerY()>650 || centro.obtenerY() <-50))
		{
			centro = Coordenada(rand()%600,rand()%800);
			asteroides[i].desplazamiento = Vector2D((float)rand(),(float)rand());
			if(((int)asteroides[i].desplazamiento.getX())%3==0)	asteroides[i].desplazamiento.setX(-asteroides[i].desplazamiento.getX());
			if(((int)asteroides[i].desplazamiento.getY())%3==0)	asteroides[i].desplazamiento.setY(-asteroides[i].desplazamiento.getY());
			asteroides[i].desplazamiento.normaliza();
		}
		asteroides[i].posicionaCentro(Coordenada(centro.obtenerX()+ 1000/asteroides[i].calcArea()*asteroides[i].desplazamiento.getX(), centro.obtenerY() + 1000/asteroides[i].calcArea()*asteroides[i].desplazamiento.getY()));
		asteroides[i].rota(1000/asteroides[i].calcArea());
	}
}
void GameProyecto:: handleEvents()
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
void GameProyecto:: clean()
{
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}
bool GameProyecto:: running()
{
	return m_bRunning;
}
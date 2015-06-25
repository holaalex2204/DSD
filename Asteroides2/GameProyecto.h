#ifndef __GameProyecto__
#define __GameProyecto__
#include <iostream>
#include <vector>
#include "Coordenada.h"
#include "Asteroide.h"
#include <SDL2/SDL.h>
class GameProyecto
{
public:
	GameProyecto();
	~GameProyecto() ;
	void init(char*, int , int , int ,int , int, int);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running();
private:
	bool m_bRunning;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture *tex;
	SDL_Surface *bmp;
	vector<Asteroide> asteroides;
};
#endif
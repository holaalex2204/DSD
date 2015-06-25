#ifndef __Game__
#define __Game__
#include <iostream>
#include <SDL2/SDL.h>
class Game
{
public:
	Game();
	~Game() ;
	void init(char*, int , int , int ,int , int);
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
};
#endif
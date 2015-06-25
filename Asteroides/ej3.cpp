#include "GameProyecto.h"
#include "Coordenada.h"
#include "Asteroide.h"
#include <iostream>
#include <vector>
using namespace std;
GameProyecto* g_game = 0;
int main(int argc, char* argv[])
{
	g_game = new GameProyecto();
	g_game->init("Proyecto Asteroides", 100, 50, 600, 800, SDL_WINDOW_SHOWN,10);
	while(g_game->running())
	{ 
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
}
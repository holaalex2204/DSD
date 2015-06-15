sdl1:  sdl1.cpp
	g++ -std=c++11 sdl1.cpp -o sdl1 -lSDL2
compile: sdl1.o  Coordenada.o Asteroide.o GameProyecto.o
	clear
	g++ ej3.cpp GameProyecto.o Coordenada.o Asteroide.o Vector2D.o -o ej3 -lSDL2
GameProyecto.o: GameProyecto.cpp GameProyecto.h Coordenada.o Asteroide.o Vector2D.o
	g++ GameProyecto.cpp Asteroide.o Coordenada.o Vector2D.o -std=c++11 sdl1.cpp -c -lSDL2
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp  -c -std=c++11
Asteroide.o: Asteroide.cpp Asteroide.h Vector2D.o
	g++ Asteroide.cpp Coordenada.o Vector2D.o -c -std=c++11	
Vector2D.o: 
	g++ Vector2D.cpp -c -std=c++11	
clean:
	rm *.o -f
run: compile
	./ej3
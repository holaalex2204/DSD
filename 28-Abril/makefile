Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
Poligono2.o: Poligono2.cpp Coordenada.o Poligono2.h
	g++ Poligono2.cpp -c	
ej4: ej4.cpp Poligono2.o
	g++ ej4.cpp Poligono2.o Coordenada.o -o ej4.o	
clean:
	rm *.o -f
run: clean ej4
	clear
	./ej4.o
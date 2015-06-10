ej1: ej1.cpp Poligono.o
	g++ ej1.cpp -o ej1.o
ej2: ej2.cpp Poligono.o
	g++ ej2.cpp Poligono.o Coordenada.o -o ej2.o
ej3: ej3.cpp Poligono.o
	g++ ej3.cpp Poligono.o Coordenada.o -o ej3.o	
Poligono2.o: Poligono2.cpp Coordenada.o Poligono2.h
	g++ Poligono2.cpp -c	
ej4: ej4.cpp Poligono2.o
	g++ ej4.cpp Poligono2.o Coordenada.o -o ej4.o	
Poligono.o: Poligono.cpp Coordenada.o Poligono.h
	g++ Poligono.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
clean:
	rm *.o -f
run: clean ej2 ej1 ej3 ej4
	clear
	time ./ej3.o
	time ./ej4.o
	./ej2.o
	./ej1.o
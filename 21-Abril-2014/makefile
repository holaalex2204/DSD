ej4: ej4.cpp Rectangulo.o
	g++ ej4.cpp Rectangulo.o Coordenada.o -o ej4.o
ej5: ej5.cpp Paralelepipedo.o
	g++ ej5.cpp Paralelepipedo.o Coordenada3D.o -o ej5.o
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Paralelepipedo.o: Paralelepipedo.cpp Coordenada3D.o Paralelepipedo.h
	g++ Paralelepipedo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
Coordenada3D.o: Coordenada3D.cpp Coordenada3D.h
	g++ Coordenada3D.cpp -c
clean:
	rm *.o -f
run: clean ej4 ej5
	clear
	./ej4.o
	./ej5.o
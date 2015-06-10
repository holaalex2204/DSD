compile: clean
	g++ Fecha.cpp -c
	g++ programa2_2.cpp Fecha.o -o programa2_2.o
clean:
	rm *.o -f
run: compile
	./programa2_2.o
runTime: compile
	time ./programa2_2.o
ej3: ej3.cpp Poligono.o
	g++ ej3.cpp Poligono.o Coordenada.o -o ej3.o	
clean: 
	rm -rf *.out
	rm -rf *.o
socket.out: main.cpp SocketDatagrama.o
	g++ main.cpp PaqueteDatagrama.o SocketDatagrama.o -o socket.out -fpermissive
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
run: clean socket.out
	clear
	./socket.out "127.0.0.1" 7000 hola.jpg
	./socket.out "127.0.0.1" 7000 hola.txt

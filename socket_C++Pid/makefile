socket.out: main.cpp SocketDatagrama.o
	g++ main.cpp PaqueteDatagrama.o SocketDatagrama.o -o socket.out
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
run: socket.out
	clear
	./socket.out

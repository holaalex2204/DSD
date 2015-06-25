clean: 
	rm -rf *.out
	rm -rf *.o
server.out: server.cpp SocketDatagrama.o
	g++ server.cpp PaqueteDatagrama.o SocketDatagrama.o -o server.out -pthread -fpermissive
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
run: clean server.out
	clear
	./server.out 7777

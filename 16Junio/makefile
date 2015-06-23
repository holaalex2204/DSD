clean: 
	rm -rf *.out
	rm -rf *.o
socket.out: main.cpp SocketDatagrama.o
	g++ main.cpp PaqueteDatagrama.o SocketDatagrama.o -o socket.out -pthread -fpermissive
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
run: clean socket.out
	clear
	./socket.out "192.168.0.115" 7000 "10_servidor_archivos_ver5.pdf" 

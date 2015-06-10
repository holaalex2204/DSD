compile:clean PaqueteDatagrama.o SocketDatagrama.o 
	g++ main.cpp PaqueteDatagrama.cpp SocketDatagrama.cpp -Wwrite-strings -fpermissive 
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	clear
	g++ PaqueteDatagrama.cpp -c -Wno-write-strings -fpermissive
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp -c -Wno-write-strings
clean:
	rm *.o -f
run: clean compile
	clear
	./a.out 
compile:clean cliente.out server.out
cliente.out:
	gcc cliente.c -std=c99 -Wformat -Wimplicit-function-declaration -o cliente.out
clean:
	rm -f *.out
server.out:
	gcc servidor.c -Wimplicit-function-declaration -std=gnu99 -o server.out
runServer: compile
	clear
	./server.out
runClient: compile
	clear
	./cliente.out < ips.txt
	
	

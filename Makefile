CC = g++ 
all: main.o loaddata.o graph.o betterload.o
	$(CC) o/main.o o/loaddata.o o/graph.o o/betterload.o -o program
	./program
main.o: cpp/main.cpp hh/main.hh
	$(CC) cpp/main.cpp -c -o o/main.o
loaddata.o: cpp/loaddata.cpp hh/loaddata.hh
	$(CC) cpp/loaddata.cpp -c -o o/loaddata.o
graph.o: cpp/graph.cpp hh/graph.hh
	$(CC) cpp/graph.cpp -c -o o/graph.o
betterload.o: cpp/betterload.cpp hh/betterload.hh
	$(CC) cpp/betterload.cpp -c -o o/betterload.o
clean:
	@echo Usuwam gotowe pliki
	@rm -f o/*.o program

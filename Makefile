CC = g++ -std=c++14 -g

all: makedir o/main.o o/stops.o o/loadbinary.o o/dfs.o o/bfs.o o/firstsearch.o  o/tinyxml2.o o/astar.o 
	$(CC) 	 o/main.o o/stops.o o/loadbinary.o o/dfs.o o/bfs.o o/firstsearch.o  o/tinyxml2.o o/astar.o -o program
o/main.o: cpp/main.cpp hh/main.hh
	$(CC) cpp/main.cpp -c -o o/main.o
makedir:
	@mkdir -p o
o/astar.o: cpp/astar.cpp hh/astar.hh
	$(CC) cpp/astar.cpp -c -o o/astar.o
o/dfs.o: cpp/dfs.cpp hh/dfs.hh
	$(CC) cpp/dfs.cpp -c -o o/dfs.o
o/bfs.o: cpp/bfs.cpp hh/bfs.hh
	$(CC) cpp/bfs.cpp -c -o o/bfs.o
#o/interfaces.o: cpp/interfaces.cpp hh/interfaces.hh
#	$(CC) cpp/interfaces.cpp -c -o o/interfaces.o
o/loadbinary.o: cpp/loadbinary.cpp hh/loadbinary.hh
	$(CC) cpp/loadbinary.cpp -c -o o/loadbinary.o
o/tinyxml2.o:  cpp/tinyxml2.cpp hh/tinyxml2.hh
	$(CC)  cpp/tinyxml2.cpp -c -o o/tinyxml2.o
o/stops.o: cpp/stops.cpp hh/stops.hh
	$(CC) cpp/stops.cpp -c -o o/stops.o
#o/gui.o: cpp/gui.cpp hh/gui.hh
#	$(CC) cpp/gui.cpp -c -o o/gui.o
#o/betterdfs.o: cpp/betterdfs.cpp hh/betterdfs.hh
#	$(CC) cpp/betterdfs.cpp -c -o o/betterdfs.o
o/firstsearch.o: cpp/firstsearch.cpp hh/firstsearch.hh
	$(CC) cpp/firstsearch.cpp -c -o o/firstsearch.o
clean:
	@echo Usuwam gotowe pliki
	@rm -f o/*.o program

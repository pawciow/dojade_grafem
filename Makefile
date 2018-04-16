CC = g++ -std=c++14 -g 

all: o/main.o  o/interfaces.o o/loadbinary.o o/tinyxml2.o o/astar.o o/bfs.o o/dfs.o
	$(CC) o/main.o o/astar.o o/bfs.o o/dfs.o o/interfaces.o o/loadbinary.o o/tinyxml2.o -o program
o/main.o: cpp/main.cpp hh/main.hh
	$(CC) cpp/main.cpp -c -o o/main.o
o/astar.o: cpp/astar.cpp hh/astar.hh
	$(CC) cpp/astar.cpp -c -o o/astar.o
o/dfs.o: cpp/dfs.cpp hh/dfs.hh 
	$(CC) cpp/dfs.cpp -c -o o/dfs.o	
o/bfs.o: cpp/bfs.cpp hh/bfs.hh 
	$(CC) cpp/bfs.cpp -c -o o/bfs.o
o/interfaces.o: cpp/interfaces.cpp hh/interfaces.hh
	$(CC) cpp/interfaces.cpp -c -o o/interfaces.o
o/loadbinary.o: cpp/loadbinary.cpp hh/loadbinary.hh
	$(CC) cpp/loadbinary.cpp -c -o o/loadbinary.o
o/tinyxml2.o:  cpp/tinyxml2.cpp hh/tinyxml2.hh
	$(CC)  cpp/tinyxml2.cpp -c -o o/tinyxml2.o
clean:
	@echo Usuwam gotowe pliki
	@rm -f o/*.o program

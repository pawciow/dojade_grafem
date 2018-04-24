//#include "../hh/main.hh"
#include "../hh/gui.hh"
#include "../hh/betterdfs.hh"

#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"

using namespace std;




int main()	{

	const int FROM_TEST = 7;
	const int DESTINATION_TEST = 130;


	cout <<'\n'<< "Start:" << endl;

// Gui interfejs;/////////////////////////

	LoadData *test = new LoadData();
	auto test1 = test->stops;
	auto test2 = test->stops;
	auto test3 = test->stops;

	cout << "Begin stop: " << test->stops[FROM_TEST]->stop_name << endl;
	cout << "End stop: " << test->stops[DESTINATION_TEST]->stop_name << endl;

	DepthFirstSearch DFS(test1);
	DFS.findPath(test1[FROM_TEST],test1[DESTINATION_TEST]);

	BreadthFirstSearch BFS(test2);
	BFS.findPath(test2[FROM_TEST],test2[DESTINATION_TEST]);


	 aStar astar(test3);
	 astar.findPath(test3[FROM_TEST], test3[DESTINATION_TEST]);
	 astar.printPath();


	return 0;
}

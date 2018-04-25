//#include "../hh/main.hh"
#include "../hh/gui.hh"
#include "../hh/betterdfs.hh"

#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"

using namespace std;




int main()
{
	const int loopRepeats = 100;
	long long int dfsMediumTime = 0;int dfsMediumNodesCount = 0;
	long long int bfsMediumTime = 0; int bfsMediumNodesCount = 0;
	long long int aStarMediumTime = 0; int aStarMediumNodesCount = 0;
	for(int i = 0; i < loopRepeats ; i++)
{
	const int FROM_TEST = 122;
	const int DESTINATION_TEST = 91 ;


	cout <<'\n'<< "Start:" << endl;


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
	 //astar.printPath();

	 //DFS.printResults();
	 dfsMediumTime += DFS.upTime;
	 dfsMediumNodesCount += DFS.nodesVisited;

	 //BFS.printResults();
	 bfsMediumTime += BFS.upTime;
	 bfsMediumNodesCount += BFS.nodesVisited;

	 //astar.printResults();
	 aStarMediumTime += astar.upTime;
	 aStarMediumNodesCount += astar.nodesVisited;

	 //Gui interfejs;/////////////////////////
}
	 dfsMediumTime /= loopRepeats;
	 dfsMediumNodesCount /= loopRepeats;
	 cout << "Medium statistics for DFS: \n"
		  << "Time : " << dfsMediumTime << endl
		  << "Nodes Count : " << dfsMediumNodesCount << endl;

	 bfsMediumTime /= loopRepeats;
	 bfsMediumNodesCount /= loopRepeats;
	 cout << "Medium statistics for BFS: \n"
		  << "Time : " << bfsMediumTime << endl
		  << "Nodes Count : " << bfsMediumNodesCount << endl;

	 aStarMediumTime /= loopRepeats;
	 aStarMediumNodesCount /= loopRepeats;
	 cout << "Medium statistics for A*: \n"
		  << "Time : " << aStarMediumTime << endl
		  << "Nodes Count : " << aStarMediumNodesCount << endl;



	return 0;
}

//#include "../hh/main.hh"
#include "../hh/gui.hh"
#include "../hh/betterdfs.hh"

#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"

using namespace std;


// auto findPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect)
// {
// 	for(auto&& e: Vect)
// 	{
// 		if(e->stop_name == destination->previous)
// 		{
// 			return e;
// 		}
// 	}
//
// }
// auto findTimeAndSetLine(const Stop* from,const Stop* destination, string & tram)
// {
// 	for(auto&& It: from->connections)
// 	{
// 		if(It.destination_stop == destination)
// 		{
// 			tram = It.line_id;
// 			return It.travel_time;
// 		}
// 	}
// 	return -1; // Czas ujemny - nie znalazlo polaczenia
// }
//
// void reconstructPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect)
// {
// 	cout << "Sciezki:" << endl << destination->stop_name;
//
// 	auto e = destination;
// 	auto time = 0;
// 	auto SummarizedTime = 0;
// 	string ex = "WoW";
// 	bool X = true;
// 	while(X)
// 	{
// 		auto tmp_e = e;
// 		e = findPath(from, e, Vect);
// 		time = findTimeAndSetLine(e, tmp_e, ex);
// 		SummarizedTime += time;
// 		if(time == -1)
// 		{
// 			cerr << "NO PATH WAS FOUND !!";
// 			break;
// 		}
// 		cout << e->stop_name <<" czas dotarcia: "<< time <<" Tramwaj: "<< ex << endl;
// 		if (e == from)
// 			X = false;
//
// 	}
// 	cout << "Time for whole route is : " << SummarizedTime << endl;
// }
//

int main()	{

	const int FROM_TEST = 2;
	const int DESTINATION_TEST = 10;


	cout <<'\n'<< "Start:" << endl;

// Gui interfejs;/////////////////////////

LoadData *test = new LoadData();
BetterDFS dfs(test->stops);
cout << "Begin stop: " << test->stops[FROM_TEST]->stop_name << endl;
cout << "End stop: " << test->stops[DESTINATION_TEST]->stop_name << endl;
dfs.findPath(test->stops[FROM_TEST],test->stops[DESTINATION_TEST]);

	// LoadData *test = new LoadData();
	// cout << "Begin stop: " << test->stops[FROM_TEST]->stop_name << endl;
	// cout << "End stop: " << test->stops[DESTINATION_TEST]->stop_name << endl;
	//
	// cout << "\n To jest DFS:";
	// DFS dfs(test->stops);
	// dfs(test->stops, test->stops[FROM_TEST]);
	// reconstructPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST], test->stops);
	// free(test);
	//
	// cout << "\n To jest A*";
	// LoadData *test1 = new LoadData();
	// aStar astar(test1->stops);
	// astar.findPath(test1->stops[FROM_TEST], test1->stops[DESTINATION_TEST]);
	// astar.printPath();
	// free(test1);
	//
	// cout << "\n To jest BFS";
	// LoadData *test2 = new LoadData();
	// BFS bfs(test2->stops);
	// bfs(test2->stops, test2->stops[FROM_TEST] );
	// reconstructPath(test2->stops[FROM_TEST], test2->stops[DESTINATION_TEST], test2->stops);
	// free(test2);

	return 0;
}

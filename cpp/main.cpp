//#include "../hh/main.hh"
#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"

using namespace std;


auto printPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect)
{
	for(auto&& e: Vect)
	{
		if(e->stop_name == destination->previous)
			{
				cout << endl << e->stop_name;
				return e;
			}
	}

}
void reconstructPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect)
{
	cout << "Sciezki:" << endl << destination->stop_name;

	auto e = destination;
	bool X = true;
	while(X)
	{
		e = printPath(from, e, Vect);
		if (e == from)
			X = false;

	}
}


int main() {

	const int FROM_TEST = 1;
	const int DESTINATION_TEST = 15; //dziwne, niektore przystanki nie dzialaja w algorytmie

	cout <<'\n'<< "Start:" << endl;
	LoadData *test = new LoadData();// ładuje w konstruktorze

	DFS dfs(test->stops);
	dfs(test->stops, test->stops[FROM_TEST]);

	reconstructPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST], test->stops);

	/*aStar astar(test->stops);
	astar.findPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST]);
	astar.printPath();*/
	//BĘDĘ MUSIAŁ DODAĆ NAZWY LINI KTÓRYMI SIE JEDZIE

  /*BFS bfs(test->stops);
  bfs(test->stops, test->stops[FROM_TEST] ); // przystanek nr 21 nie dziala??
  cout << "bfs done \n";
  //cout << bfs;
  printPath(FROM_TEST,DESTINATION_TEST,test->stops);*/

  return 0;
}

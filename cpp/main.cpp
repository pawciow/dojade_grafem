//#include "../hh/main.hh"
#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"

using namespace std;


auto findPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect)
{
	for(auto&& e: Vect)
	{
		if(e->stop_name == destination->previous)
		{
			return e;
		}
	}

}
auto findTimeAndSetLine(const Stop* from,const Stop* destination, string & tram)
{
	for(auto&& It: from->connections)
	{
		if(It.destination_stop == destination)
		{
			tram = It.line_id;
			return It.travel_time;
		}
	}
	return -1; // Czas ujemny - nie znalazlo polaczenia
}

void reconstructPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect)
{
	cout << "Sciezki:" << endl << destination->stop_name;

	auto e = destination;
	auto time = 0;
	auto SummarizedTime = 0;
	string ex = "WoW";
	bool X = true;
	while(X)
	{
		auto tmp_e = e;
		e = findPath(from, e, Vect);
		time = findTimeAndSetLine(e, tmp_e, ex);
		SummarizedTime += time;
		if(time == -1)
		{
			cerr << "NO PATH WAS FOUND !!";
			break;
		}
		cout << e->stop_name <<" czas dotarcia: "<< time <<" Tramwaj: "<< ex << endl;
		if (e == from)
			X = false;

<<<<<<< HEAD
	const int FROM_TEST = 21;
	const int DESTINATION_TEST = 124; //dziwne, niektore przystanki nie dzialaja w algorytmie
//15 do 82
  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();// ładuje w konstruktorze
	//
  //  DFS dfs(test->stops);
  //  dfs(test->stops, test->stops[FROM_TEST]);
	//
   cout << "Going to: " << test->stops[DESTINATION_TEST]->returnStopName();
  //  //test->stops[DESTINATION_TEST]->print_stop_specific();
   cout << " from:"		<< test->stops[FROM_TEST]->returnStopName()<<'\n'<<endl;
  // // test->stops[FROM_TEST]->print_stop_specific();
  //  cout << "\nPath is:" << test->stops[DESTINATION_TEST]->previous <<" \n";
	//
	//
  //  printPath(FROM_TEST,DESTINATION_TEST,test->stops);
	//
  // printPath(FROM_TEST, DESTINATION_TEST, test->stops);
	aStar astar(test->stops);
	// test->stops[FROM_TEST]->print_stop_specific();
	astar.findPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST]);
	astar.printPath();
=======
	}
	cout << "Time for whole route is : " << SummarizedTime << endl;
}


int main()	{

	const int FROM_TEST = 55;
	const int DESTINATION_TEST = 54;

	//				WAŹNE:
	//	Niektore przystanki sa puste - wada konstrukcyjna naszego wczytywania,
	//	przez to czasem nie znajduje polaczenia, chociaz nazwe przystanku ma
	// Symulowalem 0P/0L, 1, 3

	cout <<'\n'<< "Start:" << endl;

	LoadData *test = new LoadData();// ładuje w konstruktorze
	cout << "Begin stop: " << test->stops[FROM_TEST]->stop_name << endl;
	cout << "End stop: " << test->stops[DESTINATION_TEST]->stop_name << endl;

	DFS dfs(test->stops);
	dfs(test->stops, test->stops[FROM_TEST]);
>>>>>>> ff89fb82adb31a47cb84a8c1bcdef02a29ca0717

	reconstructPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST], test->stops);

	/*aStar astar(test->stops);
	astar.findPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST]);
	astar.printPath();*/
	//BĘDĘ MUSIAŁ DODAĆ NAZWY LINI KTÓRYMI SIE JEDZIE

	/*BFS bfs(test->stops);
	bfs(test->stops, test->stops[FROM_TEST] ); // przystanek nr 21 nie dziala??
	cout << "bfs done \n";

	reconstructPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST], test->stops);
	*/
	return 0;
}

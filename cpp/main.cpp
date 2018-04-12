//#include "../hh/main.hh"
#include "../hh/loadbinary.hh"
#include "../hh/graph.hh"
using namespace std;

ostream& operator<<(ostream& out, const IResults results)
{
	out << "Route: " << endl;
	for(auto& e: results.Path)
		out << " Przystanek: " << e.stopName << " Tramwaj " << e.lineName << endl;
	return out;
}

void printPath(int vectorNumbBegin, int vectorNumbEnd, vector<Stop*> Vect)
{
	string stop = Vect[vectorNumbBegin]->returnStopName();
	string begin = Vect[vectorNumbEnd]->returnStopName();
	//cout << begin << endl;
	while(true)
	{
		for(auto& It: Vect)
		{
			if(It->returnStopName() == begin)
			{
				cout << begin << endl;
				begin = It->previous;
			}
		}

	}
	cout << stop << endl;

}


int main() {
	const int TEST = 21; //dziwne, niektore przystanki nie dzialaja w algorytmie
  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();// ładuje w konstruktorze

   DFS dfs(test->stops);
   dfs(test->stops);
   cout << dfs;


  BFS bfs(test->stops, TEST );
  bfs(test->stops, TEST );
  cout << "bfs done \n";
  cout << bfs;

  cout<< test->stops[0]->returnStopName() << "from:" << test->stops[4]->previous << endl;
  printPath(0,4,test->stops);
  return 0;
}

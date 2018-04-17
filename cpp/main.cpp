//#include "../hh/main.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"
#include "../hh/dfs.hh"
#include "../hh/bfs.hh"

using namespace std;


void printPath(int vectorNumbBegin, int vectorNumbEnd, vector<Stop*> Vect)
{
	string stop = Vect[vectorNumbBegin]->returnStopName();
	string begin = Vect[vectorNumbEnd]->returnStopName();
	//cout << begin << endl;
	bool STOP = false;
	while(STOP)
	{
		for(auto& It: Vect)
		{
			if(It->returnStopName() == begin)
			{
				cout << begin << endl;
				begin = It->previous;
			}
			/*if(It->previous == stop) Bo nie dziala, trzeba dopracowac
			{
				STOP = false;
				break;
			}*/
		}

	}
	cout << stop << endl;

}


int main() {
	const int TEST = 22; //dziwne, niektore przystanki nie dzialaja w algorytmie
  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();// ładuje w konstruktorze

   //DFS dfs(test->stops);
   //dfs(test->stops);
   //cout << dfs;


  BFS bfs(test->stops, TEST );
  bfs(test->stops, TEST ); // przystanek nr 21 nie dziala??
  cout << "bfs done \n";
  //cout << bfs;

  cout<< test->stops[1]->returnStopName() << " from: " << test->stops[TEST]->previous << endl;
  //printPath(1,TEST,test->stops);
  return 0;
}

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
	bool STOP = true;
	while(STOP)
	{
		for(auto& It: Vect)
		{
			if(It->returnStopName() == stop)
			{
				cout << begin << endl;
				stop = It->previous;
			}
			if(It->returnStopName() == begin) //Bo nie dziala, trzeba dopracowac
			{
				STOP = false;
				break;
			}
		}

	}
	cout << stop << endl;

}


int main() {

	const int FROM_TEST = 4;
	const int DESTINATION_TEST = 22; //dziwne, niektore przystanki nie dzialaja w algorytmie

  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();// ładuje w konstruktorze

   DFS dfs(test->stops);
   dfs(test->stops);
   //cout << dfs;
   cout << "Going to: " << test->stops[DESTINATION_TEST]->returnStopName()
		<< " from:" << test->stops[FROM_TEST]->returnStopName() << endl;
   cout << "Path is: \n" << test->stops[FROM_TEST]->previous << endl;

   printPath(FROM_TEST,DESTINATION_TEST,test->stops);



  BFS bfs(test->stops, FROM_TEST );
  bfs(test->stops, FROM_TEST ); // przystanek nr 21 nie dziala??
  cout << "bfs done \n";
  //cout << bfs;

  cout  <<"Going to: "<< test->stops[DESTINATION_TEST]->returnStopName()
		<< " from: "   << test->stops[FROM_TEST]->returnStopName() << endl;
  cout << "Path is: \n" << test->stops[FROM_TEST]->previous << endl;

  printPath(FROM_TEST,DESTINATION_TEST,test->stops);
 // cout<< test->stops[2]->returnStopName() << " from: " << test->stops[TEST]->previous << endl;
  //printPath(1,TEST,test->stops);

  return 0;
}

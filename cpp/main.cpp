//#include "../hh/main.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"
#include "../hh/dfs.hh"
#include "../hh/bfs.hh"

using namespace std;


void printPath(const int vectorNumbBegin,const int vectorNumbEnd,const vector<Stop*> & Vect)
{
	string stop = Vect[vectorNumbBegin]->returnStopName();
	string begin = Vect[vectorNumbEnd]->returnStopName();
	int dupa= 0 ;
	bool STOP = true;
	while(STOP)
	{
		for(auto& It: Vect)
		{
			if(It->returnStopName() == begin) // Bo nie dziala, trzeba dopracowac
			{
				STOP = false;
				break;
			}

			if(It->returnStopName() == stop)
			{
				dupa++;
				cout << It->returnStopName() << endl;
				stop = It->previous;
			}
		}
	}
	cout << dupa << endl;

}


int main() {

	const int FROM_TEST = 1;
	const int DESTINATION_TEST = 15; //dziwne, niektore przystanki nie dzialaja w algorytmie

  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();// ładuje w konstruktorze

   DFS dfs(test->stops);
   dfs(test->stops, test->stops[FROM_TEST]);

   cout << "Going to: " << test->stops[DESTINATION_TEST]->returnStopName();
   //test->stops[DESTINATION_TEST]->print_stop_specific();
   cout << " from:"		<< test->stops[FROM_TEST]->returnStopName();
  // test->stops[FROM_TEST]->print_stop_specific();
   cout << "\nPath is:" << test->stops[DESTINATION_TEST]->previous <<" \n";


   printPath(FROM_TEST,DESTINATION_TEST,test->stops);


  /*BFS bfs(test->stops);
  bfs(test->stops, test->stops[FROM_TEST] ); // przystanek nr 21 nie dziala??
  cout << "bfs done \n";
  //cout << bfs;

  cout << "Going to: "   << test->stops[DESTINATION_TEST]->returnStopName()
	   << " from: "   	 << test->stops[FROM_TEST]->returnStopName();
  cout << " \n Path is:" << test->stops[FROM_TEST]->previous << endl;

  printPath(FROM_TEST,DESTINATION_TEST,test->stops);*/

  return 0;
}

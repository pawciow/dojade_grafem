//#include "../hh/main.hh"
#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"

using namespace std;

void printPath(int vectorNumbBegin, int vectorNumbEnd, vector<Stop *> Vect) {
  string stop = Vect[vectorNumbBegin]->returnStopName();
  string begin = Vect[vectorNumbEnd]->returnStopName();
  // cout << begin << endl;
  bool STOP = true;
  while (STOP) {
    for (auto &It : Vect) {
      if (It->returnStopName() == stop) {
        cout << begin << endl;
        stop = It->previous;
      }
      if (It->returnStopName() == begin) // Bo nie dziala, trzeba dopracowac
      {
        STOP = false;
        break;
      }
    }
  }
  cout << stop << endl;
}

int main() {

  const int FROM_TEST = 6;
  const int DESTINATION_TEST =
      9; // dziwne, niektore przystanki nie dzialaja w algorytmie

  cout << '\n' << "Start:" << endl;
  LoadData *test = new LoadData(); // ładuje w konstruktorze

  DFS dfs(test->stops);
  dfs(test->stops, test->stops[FROM_TEST]);
  // cout << dfs;
  cout << "Going to: " << test->stops[DESTINATION_TEST]->returnStopName()
       << " from:" << test->stops[FROM_TEST]->returnStopName() << endl;
  cout << "Path is: \n" << test->stops[FROM_TEST]->previous << endl;

  printPath(FROM_TEST, DESTINATION_TEST, test->stops);

  aStar astar(test->stops);
  astar.findPath(test->stops[FROM_TEST], test->stops[DESTINATION_TEST]);
  astar.printPath();
  /*BFS bfs(test->stops, FROM_TEST );
  bfs(test->stops, test->stops[FROM_TEST] ); // przystanek nr 21 nie dziala??
  cout << "bfs done \n";
  //cout << bfs;

  cout  <<"Going to: "<< test->stops[DESTINATION_TEST]->returnStopName()
                << " from: "   << test->stops[FROM_TEST]->returnStopName() <<
  endl; cout << "Path is: \n" << test->stops[FROM_TEST]->previous << endl;

  printPath(FROM_TEST,DESTINATION_TEST,test->stops);
  //printPath(1,TEST,test->stops);*/

  return 0;
}

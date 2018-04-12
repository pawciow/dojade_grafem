//#include "../hh/main.hh"
#include "../hh/loadbinary.hh"
#include "../hh/graph.hh"
using namespace std;

int main() {
  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();// ładuje w konstruktorze

   DFS dfs(test->stops);
   dfs(test->stops);
   cout << dfs;


  BFS bfs(test->stops, test->stops[0]->returnId() );
  //bfs(test->stops, test->stops[0]->returnId() );

  return 0;
}

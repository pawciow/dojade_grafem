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

int main() {
  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();// ładuje w konstruktorze

   //DFS dfs(test->stops);
   //dfs(test->stops);
   //cout << dfs;


  BFS bfs(test->stops, test->stops[1]->returnId() );
  bfs(test->stops, test->stops[1]->returnId() );

  return 0;
}

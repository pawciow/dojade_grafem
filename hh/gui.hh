#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/loadbinary.hh"
#include <algorithm>

using namespace std;

class Gui{
int startStop;
int goalStop;
LoadData *data = new LoadData();
  void findStop(string stop);
  auto findPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect);
public:
  Gui();
  void menu();

};

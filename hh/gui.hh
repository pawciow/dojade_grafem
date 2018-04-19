#include "../hh/astar.hh"
#include "../hh/bfs.hh"
#include "../hh/dfs.hh"
#include "../hh/interfaces.hh"
#include "../hh/loadbinary.hh"
#include <algorithm>

using namespace std;

class Gui{
int startStop;
int goalStop;
LoadData *data = new LoadData();
  void findStop(string stop);
  void reconstructPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect);
  auto findPath(const Stop* from,const Stop* destination, const vector<Stop*> & Vect);
  auto findTimeAndSetLine(const Stop* from,const Stop* destination, string & tram);

public:
  Gui();
  void menu();

};

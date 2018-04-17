#ifndef HH_INTERFACES_HH_
#define HH_INTERFACES_HH_

#include "../hh/loadbinary.hh"
#include <list>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Graph {};
enum colors { white, grey, black };

class IColors {
protected:
  map<int, colors> nodColors;
};
class IResults {
protected:
  struct _path {
    string lineName;
    string stopName;
    _path(string Line, string Stop) {
      lineName = Line;
      stopName = Stop;
    }
  };
  vector<_path> Path;
  friend ostream &operator<<(ostream &out, const IResults);
};

ostream &operator<<(ostream &out, const IResults);

#endif

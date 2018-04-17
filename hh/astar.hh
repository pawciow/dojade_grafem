#ifndef HH_ASTAR_HH_
#define HH_ASTAR_HH_

#include "../hh/loadbinary.hh"
#include "interfaces.hh"
#include <functional>
#include <math.h>
#include <map>
#include <queue>

// priority_queue<int, Stop, std::greater<int> > q2 > Q;
// std::priority_queue<Stop ,int, std::greater<int> > Q;

class aStar {
  std::map<int, double> distances;
  vector<Stop*> stops;

public:
  aStar(vector<Stop*> stopp);
  void calculateHeuristic(Stop *stop);
  void findPath(Stop* start, Stop* stop);
};

#endif /* HH_ASTAR_HH_ */

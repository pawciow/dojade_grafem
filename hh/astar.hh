#ifndef HH_ASTAR_HH_
#define HH_ASTAR_HH_

#include "../hh/loadbinary.hh"
#include "interfaces.hh"
#include <functional>
#include <map>
#include <math.h>
#include <queue>

class aStar {
  std::map<int, double> distances;
  vector<Stop *> stops;
  vector<Stop *> path;

public:
  aStar(vector<Stop *> stopp);
  void calculateHeuristic(Stop *stop);
  void findPath(Stop *start, Stop *stop);
  void printPath();
};

template <typename T, typename priority_t>

struct PriorityQueue {
  typedef std::pair<priority_t, T> PQElement;
  std::priority_queue<PQElement, std::vector<PQElement>,
                      std::greater<PQElement>>
      elements;
  inline bool empty() const { return elements.empty(); }

  inline void put(T item, priority_t priority) {
    elements.emplace(priority, item);
  }

  T get() {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};
template <typename Location>
std::vector<Location>
reconstruct_path(Location start, Location goal,
                          std::map<Location, Location> came_from) {
  std::vector<Location> path;
  Location current = goal;

  while (current != start) {
    path.push_back(current);
    current = came_from[current];
  }
  path.push_back(start); // optional
  std::reverse(path.begin(), path.end());
  return path;
}
#endif /* HH_ASTAR_HH_ */

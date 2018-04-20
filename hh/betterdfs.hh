#include "../hh/loadbinary.hh"
#include "interfaces.hh"
#include <functional>
#include <map>
#include <queue>

class BetterDFS {
  std::vector<Stop *> stops;
  std::map<Stop *, bool> visited;
  std::map<Stop *, Stop *> came_from;
  std::map<Stop *, std::string> connectionName;
  std::vector<Stop *> path;
  bool routefound;
  std::vector<Stop *> reconstruct_path(Stop *start, Stop *goal, std::map<Stop *, Stop *> came_from);

public:
  BetterDFS(std::vector<Stop *> nodes);
  void findPath(Stop *start, Stop *goal);
  void printPath();
};
// template <typename Location>
// std::vector<Location> reconstruct_path(Location start, Location goal,
//                                        std::map<Location, Location> came_from) {
//   std::vector<Location> path;
//   Location current = goal;
//   while (current != start) {
//     path.push_back(current);
//     current = came_from[current];
//   }
//   path.push_back(start); // optional
//   std::reverse(path.begin(), path.end());
//   return path;
// }

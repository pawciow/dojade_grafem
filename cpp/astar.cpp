#include "../hh/astar.hh"

void aStar::calculateHeuristic(Stop *stop) {
  for (auto &e : stops) {
    double tmp = (stop->localization.x - e->localization.x) *
                     (stop->localization.x - e->localization.x) +
                 (stop->localization.y - e->localization.y) *
                     (stop->localization.y - e->localization.y);
    tmp = sqrt(tmp);
    distances[e->returnId()] = tmp;
  }
}

aStar::aStar(vector<Stop *> stopp) { stops = stopp; }

// //
// std::map<int, int>& came_from;
//
void findPath(Stop *start, Stop* stop) {
  // calculateHeuristic();

  std::map<Stop *, double> cost_so_far;

  std::list<Stop *> openList;
  std::list<Stop *> closedList;

  openList.push_back(start);
  cost_so_far[start] = 0;

  while (!openList.empty()) {
    auto current = openList.front();
    openList.pop_front();
    if (current == stop) {
      std::cout << "dotarło\n";
      break;
    }
    for (auto &next : current->connections) {
      double new_cost = cost_so_far[current] + next.travel_time;
      if (cost_so_far.find(next.destination_stop) == cost_so_far.end() ||
          new_cost < cost_so_far[next.destination_stop]) {
        cost_so_far[next.destination_stop] = new_cost;
        int tmp = next.destination_stop->returnId();
        double priority =
            new_cost + distances[tmp];
      }
    }
  }
}

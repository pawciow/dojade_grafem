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

aStar::aStar(vector<Stop *> stopp) {
  stops = stopp;
  routefound = false;
}

void aStar::findPath(Stop *start, Stop *goal) {
  calculateHeuristic(goal);

  std::map<Stop *, double> cost_so_far;
  std::map<Stop *, Stop *> came_from;
  PriorityQueue<Stop *, double> frontier;

  frontier.put(start, 0);
  came_from[start] = start;
  cost_so_far[start] = 0;
  int a = 0;

  while (!frontier.empty()) {
    a++;
    Stop *current = frontier.get();

    if (current == goal) {
      std::cout << "A* dotarło\n";
      routefound = true;
      break;
    }
    for (auto next : current->connections) {
      double new_cost = cost_so_far[current] + next.travel_time;
      if (cost_so_far.find(next.destination_stop) == cost_so_far.end() ||
          new_cost < cost_so_far[next.destination_stop]) {
        cost_so_far[next.destination_stop] = new_cost;
        double priority =
            new_cost + distances[next.destination_stop->returnId()];
        frontier.put(next.destination_stop, priority);
        came_from[next.destination_stop] = current;
        connectionName[next.destination_stop] = next.line_id;
        // cout<<" AAAA "<<next.destination_stop->returnStopName()<<" BBBB
        // "<<current->returnStopName();
      }
    }
  }
  //   for (const auto &p : came_from) {
  //     std::cout << "m[" << p.first->returnStopName() << "] = " <<
  //     p.second->returnStopName()<< '\n';
  // }
  cout << "KONIEC A* " << a << endl;
  if (routefound)
  path = reconstruct_path(start, goal, came_from);
}
void aStar::printPath() {
  bool firststop = true;
  if (routefound) {
    cout << "Trasa: " << endl;
    for (auto It : path) {
      auto name = It->returnStopName();
      string line = connectionName[It];
      if (firststop == true) {
        cout << "Odjzad ze: " << name << endl;
        firststop = false;
      } else {
        cout << " tramwajem: " << line << " do: " << name << endl;
      }
    }
  } else {
    cout << " Nie znaleziono połączenia. " << endl;
  }
}

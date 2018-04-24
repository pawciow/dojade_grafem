#include "../hh/astar.hh"

void aStar::calculateHeuristic(Stop *stop) {
  for (auto &e : stops) {
    double tmp = (stop->localization.x - e->localization.x) *
                     (stop->localization.x - e->localization.x) +
                 (stop->localization.y - e->localization.y) *
                     (stop->localization.y - e->localization.y);
    tmp = sqrt(tmp);
    distances[e->returnStopName()] = tmp;
  }
}

aStar::aStar(vector<Stop *> stopp) {
  stops = stopp;
  routefound = false;
}

void aStar::findPath(Stop *start, Stop *goal)
{
  auto beginTime = std::chrono::high_resolution_clock::now();

  calculateHeuristic(goal);

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
      // ROZWIĄZANIE PROblEMU z pointerami
      string tgg = next.destination_stop->returnStopName();
      vector<Stop *>::iterator it;
      for (it = stops.begin(); it != stops.end(); ++it) {
        if (tgg == (*it)->return_stop_name()) {
          break;
        }
      }
      /////////////////////
      double new_cost = cost_so_far[current] + next.travel_time;
      if (cost_so_far.find(*it) == cost_so_far.end() ||
          new_cost < cost_so_far[*it]) {
        cost_so_far[*it] = new_cost;
        double priority = new_cost + distances[(*it)->returnStopName()];

        frontier.put(*it, priority);
        came_from[*it] = current;
        connectionName[*it] = next.line_id;
      }
    }
  }
  auto endTime = std::chrono::high_resolution_clock::now();
        long long int _time = std::chrono::duration_cast<std::chrono::microseconds>(endTime - beginTime).count();
        cout << "Time for A* : " << _time << endl;

  // cout << "KONIEC A* " << a << endl;
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
        cout << "Odjzad z: " << name << endl;
        firststop = false;
      } else {
        cout << " tramwajem: " << line << " do: " << name
             << " Łączny czas: " << cost_so_far[It] << endl;
      }
    }
  } else {
    cout << " Nie znaleziono połączenia. " << endl;
  }
}

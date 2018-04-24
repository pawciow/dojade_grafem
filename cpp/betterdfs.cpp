#include "../hh/betterdfs.hh"

BetterDFS::BetterDFS(std::vector<Stop *> nodes) {
  stops = nodes;
  for (auto &e : stops) {
    visited[e] = false;
  }
  routefound = false;
}

void BetterDFS::findPath(Stop *start, Stop *goal) {
  came_from[start] = NULL;

  std::stack<Stop *> stack;
 // queue<Stop*> stack;
  int a = 0;
  stack.push(start);
  while (!stack.empty()) {
    a++;
    // if (a > 5) {
    // break;
    // };
    auto node = stack.top();
    //auto node = stack.front();

    stack.pop();
    // node->print_stop_specific();
    if (node == goal) {
      cout << "GOAL" << endl;
      routefound = true;
      path = reconstruct_path(start, goal, came_from);
      printPath();
      break;
    }
    if (visited[node] == false) {
      visited[node] = true;
      auto edges = node->returnConnection();
      for (auto &next : edges) {
        string tgg = next.destination_stop->returnStopName();
        // cout << " For node: " << tgg << endl;
        vector<Stop *>::iterator it;
        for (it = stops.begin(); it != stops.end(); ++it) {
          if (tgg == (*it)->return_stop_name()) {
            break;
          }
        }
        stack.push(*it);
        if (came_from.find(*it) == came_from.end()) {
          came_from[*it] = node;
        }
        connectionName[*it] = next.line_id;
      }
    }
  }
}
std::vector<Stop *>
BetterDFS::reconstruct_path(Stop *start, Stop *goal,
                            std::map<Stop *, Stop *> came_from) {
  if (routefound) {
    std::vector<Stop *> path;
    auto current = goal;
    while (current != NULL) {
      path.push_back(current);
      current = came_from[current];
    }
    // path.push_back(start); // optional
    std::reverse(path.begin(), path.end());
    cout << "Path reconstructed" << endl;
    return path;
  }
}

void BetterDFS::printPath() {
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
        cout << "tramwajem: " << line << " do:\t" << name << endl;
      }
    }
  } else {
    cout << " Nie znaleziono połączenia. " << endl;
  }
}

/*
 * betterbfs.cpp
 *
 *  Created on: 24 kwi 2018
 *      Author: pawciow
 */




#include "../hh/firstsearch.hh"

firstSearch::firstSearch(std::vector<Stop *> nodes) {
  stops = nodes;
  for (auto &e : stops) {
    visited[e] = false;
  }
  routefound = false;
}

std::vector<Stop *>
firstSearch::reconstruct_path(Stop *start, Stop *goal,
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

void firstSearch::printPath()
{
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



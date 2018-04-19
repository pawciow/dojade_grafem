/*
 * dfs.cpp
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#include "../hh/dfs.hh"

DFS::DFS(const std::vector<Stop *> &aa) {
  nods=aa;
  int numberOfStops = 0;
  for (auto &p : nods) {
    nodColors[p->returnId()] = white;
    numberOfStops++;
  }
  cout << "DFS created properly. Number of white stops is: " << numberOfStops
       << endl;
}

void DFS::operator()(vector<Stop *> &nods, Stop *e) {
  for (auto &node : nods) {
    if (nodColors[node->returnId()] == white) {
      visitNode(node);
    }
  }
  // visitNode(e);
  cout << "Number of stops is: " << nodesCount << endl;
}

void DFS::visitNode(Stop *node) {
  nodColors[node->returnId()] = grey;

  auto test = node->return_stop_name();
  vector<Stop *>::iterator it;
  for (it = nods.begin(); it != nods.end(); ++it) {
    if (test == (*it)->return_stop_name()) {
      break;
    }
  }
  node = *it;
  cout<<node->return_conntections_size()<<endl;

  for (auto &p : node->connections) {
    if (nodColors[p.destination_stop->returnId()] == white) {
      // nodesCount++;
      // _path tmp(p.line_id, p.destination_stop->returnStopName());
      // Path.push_back(tmp);
      p.destination_stop->previous = node->returnStopName();
      visitNode(p.destination_stop);
    }
  }
  nodColors[node->returnId()] = black;
}

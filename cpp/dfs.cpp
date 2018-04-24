/*
 * dfs.cpp
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#include "../hh/dfs.hh"


	DepthFirstSearch::DepthFirstSearch(std::vector<Stop *> nodes)
	:  firstSearch(nodes)
	{
		;
	}

void DepthFirstSearch::findPath(Stop *start, Stop *goal)
{
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

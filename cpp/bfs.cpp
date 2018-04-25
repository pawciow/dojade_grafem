/*
 * bfs.cpp
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#include "../hh/bfs.hh"

BreadthFirstSearch::BreadthFirstSearch(std::vector<Stop *> nodes)
	:  firstSearch(nodes)
	{
		;
	}
void BreadthFirstSearch::findPath(Stop *start, Stop *goal) {


	beginTimeMeasurement();
  came_from[start] = NULL;

  queue<Stop*> stack;
  int a = 0;
  stack.push(start);
  while (!stack.empty())
  {
    a++;
    auto node = stack.front();
    stack.pop();

    if (node == goal)
    {
      cout << "GOAL" << endl;
      routefound = true;

  	endTimeMeasurement();

      cout << "Time for BFS : " << _time << endl;

      path = reconstruct_path(start, goal, came_from);
      printPath();
      break;
    }
    if (visited[node] == false)
    {
      visited[node] = true;
      auto edges = node->returnConnection();
      for (auto &next : edges)
      {
        string tgg = next.destination_stop->returnStopName();
        auto cost = next.travel_time; //DODAŁEM

        vector<Stop *>::iterator it;
        for (it = stops.begin(); it != stops.end(); ++it)
        {
          if (tgg == (*it)->return_stop_name())
          {
            break;
          }
        }
        stack.push(*it);
        if (came_from.find(*it) == came_from.end())
        {
          came_from[*it] = node;
        }
        connectionName[*it] = next.line_id;//DODAŁEM
        connectionCost[*it] = cost;
      }
    }
  }
}

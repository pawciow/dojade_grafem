/*
 * dfs.cpp
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#include "../hh/dfs.hh"

DFS::DFS(const std::vector<Stop *> & stopsVector)
{
  nods=stopsVector;
  int numberOfStops = 0;
  for (auto &p : nods)
  {
    nodColors[p->returnId()] = white;
    numberOfStops++;
  }
  cout << "DFS created properly. Number of white stops is: " << numberOfStops
       << endl;
}

void DFS::operator()(vector<Stop *> &nods, Stop *e)
{
  for (auto &node : nods)
  {
    if (nodColors[node->returnId()] == white)
    {
      visitNode(node);
    }
  }
  // visitNode(e);line_id
  cout << "Number of stops is: " << nodesCount << endl;
}
Stop* DFS::findProperStop(string toFind)
{
	Stop* found;
	for(auto& e: nods)
	{
		if(e->stop_name == toFind)
		{
			found  = e;
			break;
		}
	}
	return found;
}
void DFS::visitNode(Stop *node)
{
  nodColors[node->returnId()] = grey;

  auto test = node->return_stop_name();
  for (auto& it: nods)
  {
    if (test == it->return_stop_name())
    {
    	node = it;
    	break;
    }
  }

  for (auto &p : node->connections)
  {
    if (nodColors[p.destination_stop->returnId()] == white)
    {
      // Path.push_back(_path{p.line_id, p.destination_stop->returnStopName()});
      p.destination_stop->previous = node->returnStopName();
      Stop* goodPointer;
      for(auto& e: nods)
      {
    	  if(e->stop_name == p.destination_stop->stop_name)
    	  {
    		  cout << "" << e->stop_name << " " <<  p.destination_stop->stop_name;
    		 goodPointer = e;
    		 break;
    	  }
      }
      visitNode(goodPointer);
    }
  }
  nodColors[node->returnId()] = black;
}


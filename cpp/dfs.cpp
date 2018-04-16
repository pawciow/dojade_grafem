/*
 * dfs.cpp
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#include "../hh/dfs.hh"


DFS::DFS(const std::vector<Stop *> & nods)
{
	int numberOfStops = 0;
	for(auto& p: nods)
	{
		nodColors[p->returnId()] = white;
		numberOfStops++;
	}
	cout << "DFS created properly. Number of white stops is: " << numberOfStops << endl;
}

void DFS::operator() (vector<Stop *> nods)
{
	//cout << __FUNCTION__ << endl;
	int numberOfStops = 0;
	//for(auto& e: nods)
	auto e = nods[2];
		for(auto& p: e->connections)
		{
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				numberOfStops++;
				_path tmp( p.line_id, p.destination_stop->returnStopName());
				Path.push_back(tmp);
				p.destination_stop->previous = e->returnStopName();
				visitNode(p.destination_stop);
			}

		}
	//}
	cout << "Number of stops is: " << numberOfStops << endl;

}

void DFS::visitNode(Stop* node)
{
	nodColors[node->returnId()] = grey;
	for(auto& p : node->connections)
		{
			if (p.destination_stop==nullptr)
			{
				std::cerr<<"empty destination stop in input data - this should never happen"<<endl;
				break;
			}
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				_path tmp(p.line_id, p.destination_stop->returnStopName());
				Path.push_back(tmp);
				p.destination_stop->previous = node->returnStopName();
				visitNode(p.destination_stop);

			}
		}
	nodColors[node->returnId()] = black;

}

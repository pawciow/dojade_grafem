#include "../hh/interfaces.hh"


DFS::DFS(std::vector<Stop *> nods)
{
	for(auto& p: nods)
	{
		nodColors[p->returnId()] = white;
	}
	cout << "DFS created properly" << endl;
}

void DFS::operator() (vector<Stop *> nods)
{
	//cout << __FUNCTION__ << endl;

	for(auto& e: nods)
	{
		for(auto& p: e->connections)
		{
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				_path tmp(e->returnStopName(), p.line_id);
				Path.push_back(tmp);
				visitNode(p.destination_stop);
			}

		}
	}
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
				visitNode(p.destination_stop);
			}
		}
	nodColors[node->returnId()] = black;

}

ostream& operator<<(ostream& out, const IResults results)
{
	out << "Route: " << endl;
	for(auto& e: results.Path)
		out << "Przystanek: " << e.stopName << "Tramwaj " << e.lineName << endl;
	return out;
}

BFS::BFS(vector<Stop*> nods, int from)
{
	cout << "BFS created correctly \n";
	for(auto& e: nods)
		nodColors[e->returnId()] = white;
}

void BFS::Enqueue(vector<Stop*>& nods, int from)
{
	for (auto& p: nods[from]->connections)
	{
		Q.push(p.destination_stop);
	}
}


void BFS::operator() (vector<Stop*> nods, int from)
{
	nodColors[from] = grey;
	Enqueue(nods, from);
	while(!Q.empty())
	{
		auto e = Q.front();
		Q.pop();
		for( auto p : e->connections)
		{
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				nodColors[p.destination_stop->returnId()] == grey;
				for( auto& I : nods[from]->connections)
				{
					Q.push(I.destination_stop);
				}

			}
		}
		nodColors[e->returnId()] == black;
	}

}


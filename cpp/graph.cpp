#include "../hh/graph.hh"


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



BFS::BFS(vector<Stop*> nods, int from)
{
	cout << "BFS created correctly \n";
	for(auto& e: nods)
	{
		nodColors[e->returnId()] = white;
		for(auto& I : e->connections)
			I.fromStop = e->returnStopName();
	}
}

void BFS::Enqueue(const vector<Stop*> & nods, int from)
{
	for (auto& p: nods[from]->connections)
	{
		//cout << "im in" << endl;
		Q.push(p.destination_stop);
		//cout << __FUNCTION__ << endl;

	}
}

void BFS::Enqueue(const list<Stop::connection> & connections)
{
	for( auto& I : connections)
	{
		Q.push(I.destination_stop);
	}
}

Stop* BFS::Dequeue(queue<Stop*>& Q)
{
	Stop* e = Q.front();
	Q.pop();
	return e;
}
void BFS::operator() (vector<Stop*> nods, int from)
{
	nodColors[from] = grey;
	cout << __FUNCTION__ << endl;
	Enqueue(nods, from);
	cout << "Enquequed" << endl;


	while(!Q.empty())
	{
		auto e = Dequeue(Q);
		for( auto& p : e->connections)
		{
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				nodColors[p.destination_stop->returnId()] = grey;
				_path tmp(p.line_id, p.destination_stop->returnStopName());
				Path.push_back(tmp);
				// Enqueue(nods[from]->connections);
				p.destination_stop->previous = e->returnStopName();
				Q.push(p.destination_stop);
			}
		}
		auto key = e->returnId();
		nodColors[key] = black;
	}

}


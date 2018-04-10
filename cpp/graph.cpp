#include "../hh/graph.hh"


DFS::DFS(std::vector<Stop> nods)
{
	for(vector<Stop>::iterator p = nods.begin(); p != nods.end(); ++p)
	{
		nodColors[p->returnId()] = white;
	}
	cout << "DFS created properly" << endl;
}
void DFS::operator() (vector<Stop> nods)
{
	cout << "I'm in" << endl;
	//for(auto& e: nods)

	for(vector<Stop>::iterator e = nods.begin(); e != nods.end(); ++e)
	{
		//cout << "I'm in too" <<endl;
		for(auto& p: e->connections)
		{
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				//p.destination_stop->previous = e;
				//_path tmp(e->returnStopName(), p.line_id);
				//p.destination_stop->Path.push()
				visitNode(p.destination_stop);
		//		cout << " WOW" << p.line_id;
			}

		}
		cout << endl;
	}
}
void DFS::visitNode(Stop* node)
{
	nodColors[node->returnId()] = grey;
	for( list<Stop::connection>::iterator p = node->connections.begin(); p != node->connections.end(); ++p)
		{
			if( nodColors[p->destination_stop->returnId()] == white )
			{
				visitNode(p->destination_stop);
			}
		}
	nodColors[node->returnId()] = black;

}
ostream IResults::operator<<(ostream out)
{
	for(auto const e: Path)
		cout << "Przystanek: " << e.stopName << "Tramwaj " << e.lineName;
}

BFS::BFS(vector<Stop> nods, int from)
{
	cout << "BFS created correctly \n";
	for(auto& e: nods)
		nodColors[e.returnId()] = white;
}
void BFS::Enqueue(vector<Stop>& nods, int from) {
	for (list<Stop::connection>::iterator p = nods[from].connections.begin();
			p != nods[from].connections.end(); ++p) {
		Q.push(*p->destination_stop);
	}
}

void BFS::operator() (vector<Stop> nods, int from)
{
	nodColors[from] = grey;
	Enqueue(nods, from);
	while(!Q.empty()){
		auto e = Q.front();
		Q.pop();
		for( auto p = e.connections.begin(); p != e.connections.end(); ++p)
		{
			if( nodColors[p->destination_stop->returnId()] == white )
			{
				/*****************************/
				nodColors[p->destination_stop->returnId()] == grey; //UWAGA: TEGO NIE JESTEM PEWNY, TRZEBA SPRAWDZIĆ!!!!!!!
				/****************************/
				for( list<Stop::connection>::iterator I = nods[from].connections.begin(); I != nods[from].connections.end(); ++I)
				{
					Q.push(*I->destination_stop);
				}

			}
		}
		nodColors[e.returnId()] == black;
	}

}


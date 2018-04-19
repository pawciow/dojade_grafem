/*
 * bfs.cpp
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#include "../hh/bfs.hh"

BFS::BFS(const vector<Stop*> & nods)
{
	cout << "BFS created correctly \n";
	for(auto& e: nods)
	{
		nodColors[e->returnId()] = white;
	}
}

void BFS::Enqueue(const Stop* Stop)
{
	for( auto& I : Stop->connections)
	{
		Q.push(I.destination_stop);
		I.destination_stop->previous = Stop->stop_name;
	}
}

Stop* BFS::Dequeue(queue<Stop*>& Q)
{
	Stop* e = Q.front();
	Q.pop();
	return e;
}
void BFS::operator() (vector<Stop*> & nods, Stop* from)
{

	nodColors[from->returnId()] = grey;
	Enqueue(from);


	while(!Q.empty())
	{
		nodesCount++;
		auto e = Dequeue(Q);
		for( auto& p : e->connections)
		{
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				nodColors[p.destination_stop->returnId()] = grey; // Pomaluj na szaro
				Path.push_back( _path{p.line_id, p.destination_stop->return_stop_name()} ); // do debuggowania

				// Ta wersja dziala lepiej. Te pointery chyba rzeczywiscie ssą xd
				for(auto& Ex : nods)
				{
					if(Ex->stop_name == p.destination_stop->stop_name)
					Enqueue(Ex);
				}

				// TO STARA WERSJA - wywala sie o te pointery Enqueue(p.destination_stop);
			}
		}
		auto key = e->returnId();
		nodColors[key] = black;
	}
	cout << "Number of stops is: " << nodesCount << endl;

}

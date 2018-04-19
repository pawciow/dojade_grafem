/*
 * bfs.cpp
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#include "../hh/bfs.hh"

BFS::BFS(vector<Stop*> nods)
{
	cout << "BFS created correctly \n";
	for(auto& e: nods)
	{
		nodColors[e->returnId()] = white;
		for(auto& I : e->connections)
			I.fromStop = e->returnStopName();
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
void BFS::operator() (vector<Stop*> & nods, Stop* from)
{

	nodColors[from->returnId()] = grey;
	Enqueue(from->connections);


	while(!Q.empty())
	{
		nodesCount++;
		auto e = Dequeue(Q);
		for( auto& p : e->connections)
		{
			if( nodColors[p.destination_stop->returnId()] == white )
			{
				nodColors[p.destination_stop->returnId()] = grey;
				Path.push_back( _path{p.line_id, p.destination_stop->return_stop_name()} ); // do debuggowania
				p.destination_stop->previous = p.fromStop;
				Q.push(p.destination_stop);
			}
		}
		auto key = e->returnId();
		nodColors[key] = black;
	}
	cout << "Number of stops is: " << nodesCount << endl;

}

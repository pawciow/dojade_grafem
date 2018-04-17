/*
 * bfs.hh
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#ifndef HH_BFS_HH_
#define HH_BFS_HH_

#include "interfaces.hh"


class BFS : private IColors, public IResults
{
public:
	BFS(vector<Stop*> nods);
	void operator() (vector<Stop*> nods, Stop* from );
private:
	queue<Stop*> Q;

	void Enqueue(const vector<Stop*> & nods, Stop* from);
	void Enqueue(const list<Stop::connection> & connections);
	Stop* Dequeue(queue<Stop*>& Q);

};




#endif /* HH_BFS_HH_ */

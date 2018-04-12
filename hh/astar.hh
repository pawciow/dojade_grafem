/*
 * astar.hh
 *
 *  Created on: 11 kwi 2018
 *      Author: pawciow
 */

#ifndef HH_ASTAR_HH_
#define HH_ASTAR_HH_

#include "../hh/loadbinary.hh"
#include "../hh/graph.hh"
#include <queue>
#include <functional>

//priority_queue<int, Stop, std::greater<int> > q2 > Q;
//std::priority_queue<Stop ,int, std::greater<int> > Q;

class heuristic{

	heuristic(const list<Stop::connection> & connections);
	int* trams;

};

#endif /* HH_ASTAR_HH_ */

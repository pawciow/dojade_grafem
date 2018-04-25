/*
 * bfs.hh
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#ifndef HH_BFS_HH_
#define HH_BFS_HH_

#include "firstsearch.hh"

class BreadthFirstSearch : public firstSearch
{
public:
	BreadthFirstSearch(std::vector<Stop *> nodes);
	void findPath(Stop *start, Stop *goal);
};


#endif /* HH_BFS_HH_ */

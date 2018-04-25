/*
 * dfs.hh
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#ifndef HH_DFS_HH_
#define HH_DFS_HH_

#include "firstsearch.hh"


class DepthFirstSearch : public firstSearch
{
public:
	void findPath(Stop *start, Stop *goal);
	DepthFirstSearch(std::vector<Stop *> nodes);
};



#endif /* HH_DFS_HH_ */

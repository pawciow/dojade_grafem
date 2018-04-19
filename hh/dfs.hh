/*
 * dfs.hh
 *
 *  Created on: 16 kwi 2018
 *      Author: pawciow
 */

#ifndef HH_DFS_HH_
#define HH_DFS_HH_

#include "interfaces.hh"

class DFS : private IColors, public IResults
{
public:
	std::vector<Stop *> nods;
	DFS(const vector<Stop*> & nods);
	void operator() (vector<Stop*> & nods , Stop* e);
private:
	void visitNode(Stop*);

};



#endif /* HH_DFS_HH_ */

/*
 * betterbfs.hh
 *
 *  Created on: 24 kwi 2018
 *      Author: pawciow
 */
#include "../hh/loadbinary.hh"
#include "interfaces.hh"
#include <functional>
#include <map>
#include <queue>
#include <chrono>

#ifndef HH_BETTERBFS_HH_
#define HH_BETTERBFS_HH_

class IMeasureable
{
public:
	std::chrono::_V2::system_clock::time_point beginTime;
	std::chrono::_V2::system_clock::time_point endTime;
	long long int _time;
	void beginTimeMeasurement();
	void endTimeMeasurement();
	void printResults();
};


 class firstSearch : public IMeasureable
 {
protected:
  std::vector<Stop *> stops;
  std::map<Stop *, bool> visited;
  std::map<Stop *, Stop *> came_from;
  std::map<Stop *, std::string> connectionName;
  std::map<Stop *, double> connectionCost;

  std::vector<Stop *> path;
  bool routefound;
  std::vector<Stop *> reconstruct_path(Stop *start, Stop *goal, std::map<Stop *, Stop *> came_from);

public:
  firstSearch(std::vector<Stop *> nodes);
  virtual void findPath(Stop *start, Stop *goal) = 0;
  void printPath();
};



#endif /* HH_BETTERBFS_HH_ */

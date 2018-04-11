#pragma once
#include "../hh/stops.hh"
#include "../hh/tinyxml2.hh"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace tinyxml2;
using namespace std;

class LoadData : public Stop {
  vector<Stop> tmp_stops;
  void createStopsList(char *f_name, int variants);
  void reloadConnections(vector<Stop> target);
  void merge_stops_list();

public:
  void export_stops_list();
  vector<Stop> stops; // TYMCZASOWE XD

};

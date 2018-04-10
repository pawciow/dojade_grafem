#pragma once
#include "../hh/stops.hh"
#include "../hh/tinyxml2.hh"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace tinyxml2;
using namespace std;

class LoadData : public Stop {
  vector<Stop> stops;
  vector<Stop> tmp_stops;
  void createStopsList(char* f_name,int variants);
  void create_connections_for_stops();
  void merge_stops_list();

public:
  void export_stops_list();
};

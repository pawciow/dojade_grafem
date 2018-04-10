#pragma once
#include "../hh/stops.hh"
#include "../hh/tinyxml2.hh"
#include <iostream>
#include <vector>
#include <queue>
using namespace tinyxml2;
using namespace std;

class LoadData : public Stop {
  vector<Stop> stops;

  void createStopsList(char* f_name);
  void create_connections_for_stops();
  void clean_stops_list();

public:
  void export_stops_list();
};

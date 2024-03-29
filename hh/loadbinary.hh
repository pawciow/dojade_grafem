#pragma once
#include "../hh/stops.hh"
#include "../hh/tinyxml2.hh"

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <fstream>
#include <regex>

using namespace tinyxml2;
using namespace std;

class LoadData : public Stop {
  vector<Stop*> tmp_stops;
  void createStopsList(const char *f_name, int variants);
  void merge_stops_list();
  void loadLocalizations(const char* file) const;

public:
  auto returnStops(){return tmp_stops;};
  LoadData();
  vector<Stop*> stops; //

};

#pragma once
#include "../hh/stops.hh"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

class LoadData : public Stop {
  vector<Stop> stops;

  void progress_bar(float now, float max);
  void split(const string &s, char c, vector<string> &v);
  vector<vector<string> *> create_trips_names();
  string find_trip_name(vector<vector<string> *> list, string trip_id);
  void create_stops_list();
  void create_connections_for_stops();
  void clean_stops_list();
  static bool compareStopById(const Stop &a, const int &b) {
    return a.return_stop_id() < b;
  }
  static bool compareStopByName(const Stop &a, const string &b) {
    return a.return_stop_name() < b;
  }

  // struct {
  //   bool operator()(*vector<string> &a, *vector<string> &b) const {
  //     return (a[0][2] < b[0][2]);
  //   }
  // } compareByTrip_id;

public:
  void export_stops_list();
};

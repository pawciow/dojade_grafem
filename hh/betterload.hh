#include "../hh/stops.hh"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

class LoadData : public Stop {
  list<Stop> stops;
  float progress;
  long int time;

  void progress_bar(float now, float max);
  void split(const string &s, char c, vector<string> &v);
  vector<vector<string> *> create_trips_names();
  string find_trip_name(vector<vector<string> *> list, string trip_id);
  void create_stops_list();
  void create_connections_for_stops();
  void clean_stops_list();

public:
  void export_stops_list();
  void load_from_exported_file();
};

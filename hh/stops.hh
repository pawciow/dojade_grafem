#pragma once
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

struct Localization {
  double x = 0.0;
  double y = 0.0;
};






class Stop {
public:
  string stop_name;
  int stop_id;

  struct connection {
    string line_id;
    int travel_time;
    Stop *destination_stop;
    string fromStop;
  };

  list<connection> connections;
  Localization localization;
  string previous;

  auto returnId() { return stop_id; }

  auto returnStopName() { return stop_name; }

  void setLocalization(double X, double Y);

  void set_stop(int id, string name);

  void add_connection(string id, int time, Stop *destination);

  int return_stop_id() const { return stop_id; }

  string return_stop_name() const { return stop_name; }

  int return_conntections_size() { return connections.size(); }

  list<connection> returnConnection() { return connections; }

  void mergeConnection(list<connection> connect) {
    connections.splice(connections.end(), connect);
  }

  void print_stop_specific();

  auto findProperStop(string toFind);
};

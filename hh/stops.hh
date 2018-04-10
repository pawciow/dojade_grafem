#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Stop {
  int stop_id;
  string stop_name;
  struct connection {
    string line_id;
    int travel_time;
    Stop *destination_stop;
  };

  list<connection> connections;

public:
  void set_stop(int id, string name) {
    stop_id = id;
    stop_name = name;
  }
  void add_connection(string id, int time, Stop *destination) {
    connection temp;
    temp.line_id = id;
    temp.travel_time = time;
    temp.destination_stop = destination;
    connections.push_back(temp);
  }
  int return_stop_id() const { return stop_id; }
  string return_stop_name() const { return stop_name; }
  void print_stop_specific() {
    cout << stop_id << ' ' << stop_name << endl;
    cout << "Lista połączeń z przystanku: " << endl; // dopisać funkcje
    for (list<connection>::iterator it = connections.begin();
         it != connections.end(); ++it) {
      cout << "Id: " << (*it).line_id
           << " Czas przejzadu: " << (*it).travel_time << endl;
      cout << " Cel: " << (*it).destination_stop->return_stop_name() << endl;
    }
    cout << endl;
  }
  int return_conntections_size() { return connections.size(); }
  void print_stop_connections() {
    cout << "Id: " << stop_id << " Nazwa przystanu: " << stop_name << endl;
    cout << "Ilość połączeń z przystanku: " << connections.size()
         << endl; // dopisać funkcje
    cout << endl;
  }
  bool operator<(const Stop &stop) const {
    return stop_id < stop.return_stop_id();
  }
};

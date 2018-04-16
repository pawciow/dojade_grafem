#pragma once
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

struct Localization
{
	double x = 0.0;
	double y = 0.0;
};


class Stop {
 // int stop_id;
  Localization localization;
public:
  string stop_name;
  int stop_id;

  struct connection
  {
    string line_id;
    int travel_time;
    Stop *destination_stop;
    string fromStop;
  };

  list<connection> connections;
  string previous;

  auto returnId() {return stop_id;}
  auto returnStopName() {return stop_name;}
  void setLocalization(double X, double Y)
  {
		localization.x = X;
		localization.y = Y;
  }
  void set_stop(int id, string name) {
    stop_id = id;
    stop_name = name;
    connections.clear();
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

  int return_conntections_size() { return connections.size(); }

  list<connection> returnConnection() { return connections; }

  void replaceConnectionsPointers(vector<Stop> stops) {
    list<connection>::iterator it;
    vector<Stop>::iterator k;
    for (it = connections.begin(); it != connections.end(); ++it) {
      string nazwa = (*it).destination_stop->return_stop_name();
      cout<<nazwa<<endl;
      for (k = stops.begin(); k != stops.end(); ++k) {
        if (nazwa == k->return_stop_name()) {
          // cout<<k->return_stop_name()<<endl;
          (*it).destination_stop = &*k;
        }
      }
    }
  }
  void mergeConnection(list<connection> connect) {
    connections.splice(connections.end(), connect);
  }

  void print_stop_specific() {
    cout << stop_id << ' ' << stop_name << endl;
    cout << "Pozycja x: " << localization.x << "Pozycja y: " << localization.y <<endl;
    cout << "Lista połączeń z przystanku: " << endl; // dopisać funkcje
    for (list<connection>::iterator it = connections.begin();
         it != connections.end(); ++it) {
      cout << "Id: " << (*it).line_id
           << " Czas przejzadu: " << (*it).travel_time
           << " Cel: " << (*it).destination_stop->return_stop_name() << endl;
    }
    cout << endl;
  }
};

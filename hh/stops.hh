#include <iostream>
#include <list>
#include <string>
using namespace std;

class Stop {
  int stop_id;
  string stop_name;
  struct connection {
    int line_id;
    int travel_time;
    Stop *destination_stop;
  };

  list<connection> connections;

public:
  void set_stop(int id, string name) {
    stop_id = id;
    stop_name = name;
  }
  void add_connection(int id, int time, Stop *destination) {
    connection temp;
    temp.line_id = id;
    temp.travel_time = time;
    temp.destination_stop = destination;
    connections.push_back(temp);
  }
  int return_stop_id() { return stop_id; }
  void print_stop_specific() {
    cout << stop_id << stop_name << endl;
    cout << "Lista połączeń z przystanku: " << endl; // dopisać funkcje
    for (list<connection>::iterator it = connections.begin();
         it != connections.end(); ++it) {
      cout << "Id: " << (*it).line_id
           << " Czas przejzadu: " << (*it).travel_time
           << " Cel: " << (*it).destination_stop << endl;
    }
    cout << endl;
  }
  int return_conntections_size() { return connections.size(); }
  void print_stop_connections() {
    cout << "Nazwa przystanu: " << stop_name << endl;
    cout << "Ilość połączeń z przystanku: " << connections.size()
         << endl; // dopisać funkcje
    cout << endl;
  }
  friend ostream &operator<<(ostream &output, const Stop &D) {
    output << D.stop_id << ' ' << D.stop_name << '\n';
    return output;
  }

  friend istream &operator>>(istream &input, Stop &D) {
    // input >> D.feet >> D.inches;
    return input;
  }
};

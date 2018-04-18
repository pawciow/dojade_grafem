#include "../hh/stops.hh"

void Stop::setLocalization(double X, double Y) {
  localization.x = X;
  localization.y = Y;
}

void Stop::set_stop(int id, string name) {
  stop_id = id;
  stop_name = name;
  connections.clear();
}

void Stop::add_connection(string id, int time, Stop *destination) {
  connection temp;
  temp.line_id = id;
  temp.travel_time = time;
  temp.destination_stop = destination;
  connections.push_back(temp);
}

void Stop::print_stop_specific() {
  cout << stop_id << ' ' << stop_name << endl;
  cout << "Pozycja x: " << localization.x << " Pozycja y: " << localization.y
       << endl;
  cout << "Lista połączeń z przystanku: " << endl; // dopisać funkcje
  for (list<connection>::iterator it = connections.begin();
       it != connections.end(); ++it) {
    cout << "Id: " << (*it).line_id
         << " Czas przejzadu: " << (*it).travel_time
         << " Cel: " << (*it).destination_stop->return_stop_name() << endl;
  }
  // cout << "Poprzednik :" << previous;
  cout << endl;
}

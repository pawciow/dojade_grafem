#include "../hh/loadbinary.hh"

void LoadData::split(const string &s, char c, vector<string> &v) {
  int i = 0;
  int j = s.find(c);
  while (j >= 0) {
    v.push_back(s.substr(i, j - i));
    // cout<<(s.substr(i, j - i))<<endl; //debug
    i = ++j;
    j = s.find(c, j);
    if (j < 0) {
      v.push_back(s.substr(i, s.length()));
    }
  }
}

string LoadData::find_trip_name(vector<vector<string> *> list, string trip_id) {
  string tmp;
  for (vector<vector<string> *>::iterator p = list.begin(); p != list.end();
       ++p) {
    if (trip_id == (*p)[0][2]) {
      tmp = (*p)[0][0];
      // cout << "id stop: " << stop_id << " nazwa: " << tmp << endl;
      return tmp;
    }
  }
  return tmp = "błąd- brak tramwaju";
}

vector<vector<string> *> LoadData::create_trips_names() {
  ifstream file;
  // file.open("data/stop_times.txt");
  file.open("data/trips.txt");
  vector<string> *p = NULL;
  string tmp;
  vector<vector<string> *> names;
  while (!file.eof()) {
    getline(file, tmp, '\n');
    p = new vector<string>();
    split(tmp, ',', *p);
    names.push_back(p);
    tmp.clear();
  }
  file.close();
  // TRZEBA JAKOŚ POSORTOWAC names według stringów w names[i][0][2]
  //ŻEBY TO ZROBIĆ TRZEBA NAPISAĆ  W LOAD BINARY FUNKCJĘ W TEJ STRUKTYRZE compareStopById
  // DOBRĄ. TO CO JEST TERAZ JEST ŹLE
  // A POTEM LOWER BOUND TRZEBA ZROBIĆ W FUNKCJI find_trip_name
  // BO teraz jest mln linii kodu i każdą iteruje przez cały vector names
  // std::sort(names.begin(), names.end(),compareByTrip_id);
  // if(a)cout<<"OK"<<endl;
  for (int i = 0; i < 10; i++)
    cout << names[i][0][3] <<' '<<names[i][0][2] << endl;
  return names;
}

void LoadData::create_stops_list() {
  ifstream file;
  // file.open("data/stop_times.txt");
  file.open("data/stops.txt");
  vector<string> *p = NULL;
  string tmp;
  vector<vector<string> *> names;
  while (!file.eof()) {
    getline(file, tmp, '\n');
    p = new vector<string>();
    split(tmp, ',', *p);
    names.push_back(p);
    tmp.clear();
  }
  file.close();

  string stop_id;
  string stop_name;
  int stop_id_int;
  for (vector<vector<string> *>::iterator p = names.begin();
       p != names.end() - 2; ++p) {
    stop_id = (*p)[0][0];
    stop_id_int = atoi(stop_id.c_str()); // konwertuje do int
    stop_name = (*p)[0][2];
    Stop *tmp = new Stop();
    tmp->set_stop(stop_id_int, stop_name);
    stops.push_back(*tmp);
  }
  std::sort(stops.begin(), stops.end());
}

void LoadData::create_connections_for_stops() {
  ifstream file;
  file.open("data/stop_times.txt");
  vector<string> *p = NULL;
  string tmp;
  vector<vector<string> *> data;
  while (!file.eof()) {
    getline(file, tmp, '\n');
    p = new vector<string>();
    split(tmp, ',', *p);
    data.push_back(p);
    tmp.clear();
  }
  file.close();

  vector<vector<string> *> trips_names;
  trips_names = create_trips_names();
  string trip_id;
  string stop_id;
  int stop_id_int;
  string next_stop_id;
  int next_stop_id_int;
  bool journey_end;
  string trip_name;
  for (vector<vector<string> *>::iterator p = data.begin(); p != data.end() - 2;
       ++p) {
    trip_id = (*p)[0][0];
    if (trip_id[0] == '3') { // WARUNEK ŻE TO TRAMWAJ
      journey_end = false;
      stop_id = (*p)[0][3];
      stop_id_int = atoi(stop_id.c_str());
      int a = distance(data.begin(), p);
      int b = data.size() - 3;
      string next_stop_id;
      if (a < b) {
        next_stop_id = data[a + 1][0][3];
      } else {
        next_stop_id = stop_id;
      }
      next_stop_id_int = atoi(next_stop_id.c_str());
      if (next_stop_id_int == stop_id_int) {
        journey_end = true;
      }
      if (journey_end == false) {
        // string trip_name = find_trip_name(trips_names, trip_id);
        // int trip_name_int = atoi(trip_name.c_str());
        int trip_name_int = 10;
        std::vector<Stop>::iterator f;
        f = std::lower_bound(stops.begin(), stops.end(), stop_id_int,
                             compareStopById);
        if (f->return_stop_id() == stop_id_int) {
          Stop *pointer_to_next_stop;
          std::vector<Stop>::iterator k;
          k = std::lower_bound(stops.begin(), stops.end(), next_stop_id_int,
                               compareStopById);
          if (k->return_stop_id() == next_stop_id_int) {
            pointer_to_next_stop = &*k;
            f->add_connection(trip_name_int, 1, pointer_to_next_stop);
          }
        };
      }
    }
  }
  for (vector<vector<string> *>::iterator p = data.begin(); p != data.end();
       ++p) {
    delete *p; // usuwanie
  }
  for (vector<vector<string> *>::iterator p = trips_names.begin();
       p != trips_names.end(); ++p) {
    delete *p; // usuwanie
  }
}

void LoadData::clean_stops_list() {
  int tmp;
  for (vector<Stop>::iterator it = stops.begin(); it != stops.end(); ++it) {
    tmp = it->return_conntections_size();
    if (tmp < 1) {
      stops.erase(it);
      --it;
    }
  }
}

void LoadData::export_stops_list() {
  create_stops_list();
  create_connections_for_stops();
  system("clear");
  // for (int i = 1; i < 6; i++) {
  //   stops[i].print_stop_connections();
  // }
  // for (int i = 500; i < 505; i++) {
  //   stops[i].print_stop_connections();
  // }
  cout << "\n Utworzono " << stops.size() << " przystanków" << endl;
  clean_stops_list();
  cout << "\n Pozostało " << stops.size() << " przystanków z połączeniami"
       << endl;
}

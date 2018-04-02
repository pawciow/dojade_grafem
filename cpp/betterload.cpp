#include "../hh/betterload.hh"
// #include "../hh/loaddata.hh
void LoadData::progress_bar(float now, float max) {
  if (((clock() - time) / CLOCKS_PER_SEC) > 1) {
    system("clear");
    cout << '\t' << now << " from " << max << endl;
    int barWidth = 70;
    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
      if (i < pos)
        std::cout << "=";
      else if (i == pos)
        std::cout << ">";
      else
        std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
    progress = now / max;
    time = clock();
  }
}

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
      string trip_name = find_trip_name(trips_names, trip_id);
      int trip_name_int = atoi(trip_name.c_str());

      for (list<Stop>::iterator it = stops.begin(); it != stops.end(); ++it) {
        int existing_id = it->return_stop_id();
        if (existing_id == stop_id_int && journey_end == false) {

          Stop *pointer_to_next_stop;
          for (list<Stop>::iterator iter = stops.begin(); iter != stops.end();
               ++iter) {
            int existing_id = iter->return_stop_id();
            // cout << next_stop_id_int << " " << existing_id << endl;
            if (next_stop_id_int == existing_id) {
              pointer_to_next_stop = &*iter;
              break;
            }
          }
          it->add_connection(trip_name_int, 1, pointer_to_next_stop);
        }
      }
    }
    progress_bar(distance(data.begin(), p), data.size());
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
  for (list<Stop>::iterator it = stops.begin(); it != stops.end(); ++it) {
    tmp = it->return_conntections_size();
    if (tmp < 1) {
      stops.erase(it);
      --it;
    }
  }
}

void LoadData::export_stops_list() {
  progress = 0.0;
  time = clock();
  create_stops_list();
  create_connections_for_stops();
  cout << "\n Utworzono " << stops.size() << " przystanków" << endl;
  clean_stops_list();
  cout << "\n Pozostało " << stops.size() << " przystanków z połączeniami"
       << endl;
}
void LoadData::load_from_exported_file() {
  ifstream file;
  // file.open("data/stop_times.txt");
  file.open("data/exported.txt");
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
}

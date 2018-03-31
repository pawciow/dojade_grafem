// #pragma once
#include "../hh/stops.hh"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class LoadData : public Stop {
  list<Stop> stops;

  void split(const string &s, char c, vector<string> &v) {
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
  vector<vector<string> *> create_stop_names() {
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
    return names;
  }
  string find_stop_name(vector<vector<string> *> list, string stop_id) {
    string tmp;
    for (vector<vector<string> *>::iterator p = list.begin();
         p != list.end() - 1; ++p) {
      if (stop_id == (*p)[0][0]) {
        tmp = (*p)[0][2];
        // cout << "id stop: " << stop_id << " nazwa: " << tmp << endl;
        return tmp;
      }
    }
    return tmp="błąd- brak nazwy";
  }

public:
  void create_stops_list() {
    ifstream file;
    // file.open("data/stop_times.txt");
    file.open("test.txt");
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
    // data[wiersz][0][kolumna]
    // kolumna legenda:
    // 0 = trip_id, 1 = arrival_time, 2 = departure_time, 3 = stop_id,
    // 4 = stop_sequence, 5 = pickup_type,
    // 6 = drop_off_type
    // data[1][0][1]; = wiersz 1 kolumna arrivaltime
    vector<vector<string> *> stop_names;
    stop_names = create_stop_names();
    // string trdip_id = data[5][0][0];
    for (vector<vector<string> *>::iterator p = data.begin();
         p != data.end()-2 ; ++p) {
      // nie liczyłem dokładnie dlaczego -2 ale jak nie dam to mi przesuwa
      // poza zakres i sypie seg fault.
      string trip_id = (*p)[0][0];
      if (trip_id[0] == '3') { // WARUNEK ŻE TO TRAMWAJ
        // cout << "OK" << endl;
        string stop_id = (*p)[0][3];
        string name = find_stop_name(stop_names, stop_id);
        int stop_id_int = atoi(stop_id.c_str());// konwertuje do int

        if (stops.size() < 1) {
          // jeżeli nie ma to stwórz 1 element listy przystanków
          // cout << "tworzę pierwszy przystanek" << endl;
          Stop *tmp = new Stop();
          tmp->set_stop(stop_id_int, name);
          stops.push_back(*tmp);
        } else { // sprawdz czy jest już taki przystanek
          bool is_stop = false;
          for (list<Stop>::iterator it = stops.begin(); it != stops.end();
               ++it) {
            int existing_id = it->return_stop_id();
            if (existing_id == stop_id_int) {
              is_stop = true;
              // jeżeli jest dodaj połączania do istniejącego przystanku
              // napisać krótki algorym który oblicza czas do następnego
              // przystanku i generuje dane do 
              // void add_connection(int id, int time, Stop *destination) {
            }
          }
          if (!is_stop) { // stwórz nowy przystanek
            // cout << "tworzę kolejny przystanek" << endl;
            Stop *tmp = new Stop();
            tmp->set_stop(stop_id_int, name);
            stops.push_back(*tmp);
          }
        }
      } else {
        // cout<<"To nie tramwajowa linia"<<endl;
      }
    }
    for (list<Stop>::iterator it = stops.begin(); it != stops.end(); ++it) {
      (*it).print_stop();
    }
    for (vector<vector<string> *>::iterator p = data.begin(); p != data.end();
         ++p) {
      delete *p; // usuwanie
    }

    // Zasada działania create_stop_names()
    //   1.Otwórz plik i wczytaj do vectora data poszczególne
    //   dane oddzielone przecinkami w tekscie
    //   mozna sie do nich dostac w nastepujacy sposób:
    //     data[wiersz][0][kolumna]
    //     kolumna legenda:
    //     0 = trip_id, 1 = arrival_time, 2 = departure_time, 3 = stop_id,
    //     4 = stop_sequence, 5 = pickup_type,
    //     6 = drop_off_type
    //     data[1][0][1]; = wiersz 1 kolumna arrivaltime
    //   2. Utwórz na tej samej zasadzie listę przystanków z innego pliku
    //   3. Przejdź przez wszystkie dane w data w poszukiwaniu połączeńt
    //     tramwajowych. Kiedy trip_id zaczyna się na 3 to oznacza tramwaj
    //   4. Jeżeli znalazło połączenie tramwajowe sprawdza też przystanek z
    //   nim połączony i od razu jego nazwę w formie tekstu.
    //   5. Jeżeli brak przystanków na liście tworzy pierwszy.
    //   6. Przeszukuje liste przystanków i sprawdza czy istanieje juz taki.
    //     jeżeli istnieje to dodaje do niego połączenie
    //     jeżeli nie to tworzy nowy przystanek i dodaje do listy.
    //   7. na koniec usuwamy z pamięci wczytane dane w liście wektorów DATA.

  };

  void return_stops(); // zwróc listę załadowanych przystanków
};

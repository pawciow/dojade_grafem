#include "../hh/loadbinary.hh"

#include <array>

void LoadData::createStopsList(const char *f_name, int variants) {
  XMLDocument doc;
  std::queue<int> czas_przejazdu;
  int id_przystanku;
  const char *nazwa_przystanku;
  tmp_stops.clear();
  doc.LoadFile(f_name);
  int wariant = 0;

  const char *nazwa_lini =
      doc.FirstChildElement("linie")->FirstChildElement("linia")->Attribute(
          "nazwa");
  XMLElement *root = doc.FirstChildElement("linie")
                         ->FirstChildElement("linia")
                         ->FirstChildElement("wariant");
  root->QueryIntAttribute("id", &wariant);

  while (wariant <= variants) {

    // cout << "Wariant: " << wariant << endl;
    int odjazd_h, odjazd_m, przyjazd_h, przyjazd_m;
    for (XMLElement *e = root->FirstChildElement("przystanek"); e != NULL;
         e = e->NextSiblingElement("przystanek")) {

      nazwa_przystanku = e->Attribute("nazwa");
      id_przystanku = atoi(e->Attribute("id"));
      // printf("Id i nazwa przystanku : %d , %s \n", id_przystanku,
      //        nazwa_przystanku);
      XMLElement *f = e->NextSiblingElement("przystanek");

      if (f != NULL) {
        XMLElement *fg = f->FirstChildElement("tabliczka");
        if (fg) {
          fg = f->FirstChildElement("tabliczka")
                   ->FirstChildElement("dzien")
                   ->FirstChildElement("godz");
          fg->QueryIntAttribute("h", &przyjazd_h);
          fg->FirstChildElement("min")->QueryIntAttribute("m", &przyjazd_m);
        }
      }
      Stop *tmp = new Stop();
      tmp->set_stop(id_przystanku, nazwa_przystanku);
      tmp_stops.push_back(tmp);
      int roznica;
      XMLElement *tt = e->FirstChildElement("tabliczka");
      if (tt) {
        tt = e->FirstChildElement("tabliczka")
                 ->FirstChildElement("dzien")
                 ->FirstChildElement("godz");
        tt->QueryIntAttribute("h", &odjazd_h);
        tt->FirstChildElement("min")->QueryIntAttribute("m", &odjazd_m);
        roznica = (przyjazd_h - odjazd_h) * 60 + przyjazd_m - odjazd_m;
        czas_przejazdu.push(roznica);
      }
    }

    for (vector<Stop*>::iterator it = tmp_stops.begin(); it != tmp_stops.end();
         ++it) {
      vector<Stop*>::iterator k = it;
      k++;
      if (k == tmp_stops.end())
      {
    	  break;
      }
      // cout<<k->return_stop_name()<<endl;
      string str = nazwa_lini;
      (*it)->add_connection(str, czas_przejazdu.front(), *k);
      czas_przejazdu.pop();
    }
    // SCAL Z AKTUALNYMI PRZYSTANKAMI
    // tmp_stops[0]->print_stop_specific();
    // tmp_stops[11].print_stop_specific();
    merge_stops_list();
    // cout<<"STOPS"<<endl;
    stops[0]->print_stop_specific();

    // stops[3].print_stop_specific();
    if( root->NextSiblingElement("wariant")!=NULL){
    root = root->NextSiblingElement("wariant");
    root->QueryIntAttribute("id", &wariant);}
  }
}
//////////////////////////////////////
void LoadData::merge_stops_list() {
  // std::sort(stops.begin(), stops.end());
  // std::sort(tmp_stops.begin(), tmp_stops.end());
  vector<Stop*>::iterator it;
  vector<Stop*>::iterator k;
  if (stops.size() == 0) {
    stops.clear();
    stops = tmp_stops;
  } else {
    for (it = tmp_stops.begin(); it != tmp_stops.end(); ++it) {
      // it->print_stop_specific();
      string tmp = (*it)->return_stop_name();
      bool powtorzenie = false;
      for (k = stops.begin(); k != stops.end(); ++k) {
        if ((*k)->return_stop_name() == tmp) {
          // cout << "taki sam przystanek" << endl;
          powtorzenie = true;
          break;
        }
      }
      if (powtorzenie) {
        // znajdz przystanek docelowy w stops iterator k
        // zamien wskaxnik
        //
        // zrob dla wszystkich połączeń
        // it->replaceConnectionsPointers(stops);
        // it->print_stop_specific();
        // k->print_stop_specific();

        (*k)->mergeConnection((*it)->returnConnection());
      } else {
        stops.push_back(*it);
      }
    }
  }
}
void LoadData::reloadConnections(vector<Stop> target) {
  for (vector<Stop>::iterator it = target.begin(); it != target.end(); ++it) {
    std::cout << "Rozmiar: " << it->return_conntections_size() << '\n';
    if (it->return_conntections_size() >= 1) {
      it->replaceConnectionsPointers(target);
    }
  }
}
void LoadData::export_stops_list() {
  std::vector<const char*> array = {
      "data/000l.xml", "data/0001.xml",  "data/0002.xml",
      "data/0003.xml", "data/0004.xml", "data/0005.xml",  "data/0006.xml",
      "data/0007.xml", "data/0008.xml", "data/0009.xml",  "data/0010.xml",
      "data/0011.xml", "data/0014.xml", "data/0015.xml",  "data/0017.xml",
      "data/0020.xml", "data/0023.xml", /*"data/00024.xml", bo nie dziala*/ "data/0031.xml",
      "data/0032.xml", "data/0033.xml"};
  int wariant = 1;
  for (int i = 0; i < array.size(); i++) {
    createStopsList(array[i], wariant);
  }

  cout << "\nUtworzono " << stops.size() << " przystanków" << endl;
  // for (vector<Stop*>::iterator it = stops.begin(); it != stops.end(); ++it) {
  //   // 20670== WYSZYŃSKIEGO
  //   if (20670 == (*it)->return_stop_id()) {
  //     (*it)->print_stop_specific();
  //   }
  // }
}

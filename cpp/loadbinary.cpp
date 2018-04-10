#include "../hh/loadbinary.hh"

void LoadData::createStopsList(char *f_name) {
  XMLDocument doc;
  vector<Stop> stops_vect;
  std::queue<int> czas_przejazdu;
  int id_przystanku;
  const char *nazwa_przystanku;

  doc.LoadFile(f_name);
  const char *nazwa_lini =
      doc.FirstChildElement("linie")->FirstChildElement("linia")->Attribute(
          "nazwa");
  XMLElement *root = doc.FirstChildElement("linie")
                         ->FirstChildElement("linia")
                         ->FirstChildElement("wariant");
  cout << "Wariant: " << root->Attribute("id") << endl;

  int odjazd_h, odjazd_m, przyjazd_h, przyjazd_m;
  for (XMLElement *e = root->FirstChildElement("przystanek"); e != NULL;
       e = e->NextSiblingElement("przystanek")) {

    nazwa_przystanku = e->Attribute("nazwa");
    id_przystanku = atoi(e->Attribute("id"));
    printf("Id i nazwa przystanku : %d , %s \n", id_przystanku,
           nazwa_przystanku);
    XMLElement *f = e->NextSiblingElement("przystanek");
    if (f != NULL) {
      XMLElement *fg = f->FirstChildElement("tabliczka")
                           ->FirstChildElement("dzien")
                           ->FirstChildElement("godz");
      fg->QueryIntAttribute("h", &przyjazd_h);
      fg->FirstChildElement("min")->QueryIntAttribute("m", &przyjazd_m);
    }
    Stop *tmp = new Stop();
    tmp->set_stop(id_przystanku, nazwa_przystanku);
    stops_vect.push_back(*tmp);
    XMLElement *tt = e->FirstChildElement("tabliczka")
                         ->FirstChildElement("dzien")
                         ->FirstChildElement("godz");
    tt->QueryIntAttribute("h", &odjazd_h);
    tt->FirstChildElement("min")->QueryIntAttribute("m", &odjazd_m);
    int roznica = (przyjazd_h - odjazd_h) * 60 + przyjazd_m - odjazd_m;
    czas_przejazdu.push(roznica);
  }

  for (vector<Stop>::iterator it = stops_vect.begin(); it != stops_vect.end();
       ++it) {
    vector<Stop>::iterator k = it;
    k++;
    // cout<<k->return_stop_name()<<endl;
    string str = nazwa_lini;
    it->add_connection(str, czas_przejazdu.front(), &*(k));
    czas_przejazdu.pop();
  }
  // SCAL Z AKTUALNYMI PRZYSTANKAMI
  // stops = stops_vect;
  stops_vect[3].print_stop_specific();
  stops = stops_vect;
  stops[3].print_stop_specific();

}

void LoadData::create_connections_for_stops() {}

void LoadData::clean_stops_list() {}

void LoadData::export_stops_list() {
  createStopsList((char *)"000l.xml");
  // cout << "\n Utworzono " << stops.size() << " przystanków" << endl;
  stops[3].print_stop_specific();
}

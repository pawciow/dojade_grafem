#include "../hh/loadbinary.hh"

#include <array>
#include <fstream>
#include <regex>

void LoadData::createStopsList(const char *f_name, int variants) {
  XMLDocument doc;
  std::queue<int> czas_przejazdu;
  int id_przystanku;
  const char *nazwa_przystanku;
  tmp_stops.clear();
  bool load_ok = doc.LoadFile(f_name);
  if (load_ok) {
    cout << "Problem z ładowaniem pliku" << endl;
  }

  int wariant = 0;
  const char *nazwa_lini;

  XMLElement *linia =
      doc.FirstChildElement("linie")->FirstChildElement("linia");
  if (linia != NULL) {
    nazwa_lini = linia->Attribute("nazwa");

    XMLElement *root = doc.FirstChildElement("linie")
                           ->FirstChildElement("linia")
                           ->FirstChildElement("wariant");
    root->QueryIntAttribute("id", &wariant);

    int loop = 0;
    while (loop < variants) {
      tmp_stops.clear();

      // cout << "Wariant: " << wariant << endl;
      int odjazd_h, odjazd_m, przyjazd_h, przyjazd_m;
      for (XMLElement *e = root->FirstChildElement("przystanek"); e != NULL;
           e = e->NextSiblingElement("przystanek")) {

        nazwa_przystanku = e->Attribute("nazwa");
        id_przystanku = atoi(e->Attribute("id"));
        // printf("Id i nazwa przystanku : %d , %s \n", id_przystanku,
        //        nazwa_przystanku);
        XMLElement *f = e->NextSiblingElement("przystanek");
        XMLElement *fg;

        Stop *tmp = new Stop();
        tmp->set_stop(id_przystanku, nazwa_przystanku);
        tmp_stops.push_back(tmp);
        /////////////OBLICZANIE CZASU PRZEJAZDU
        int roznica;
        if (f != NULL) {
          fg = f->FirstChildElement("tabliczka");
          if (fg != NULL) {
            fg = f->FirstChildElement("tabliczka")
                     ->FirstChildElement("dzien")
                     ->FirstChildElement("godz");
            fg->QueryIntAttribute("h", &przyjazd_h);
            fg->FirstChildElement("min")->QueryIntAttribute("m", &przyjazd_m);
          }
        }
        XMLElement *tt = e->FirstChildElement("tabliczka");
        if (tt != NULL) {
          tt = e->FirstChildElement("tabliczka")
                   ->FirstChildElement("dzien")
                   ->FirstChildElement("godz");
          tt->QueryIntAttribute("h", &odjazd_h);
          tt->FirstChildElement("min")->QueryIntAttribute("m", &odjazd_m);

          roznica = (przyjazd_h - odjazd_h) * 60 + przyjazd_m - odjazd_m;

        if (roznica == 0){
            roznica = 1;}
          else if (roznica < 0) {
            roznica = 4;//TYMCZASOWOOOOOOOO
            
            // fg=fg->NextSiblingElement("min");
// fg=fg->FirstChildElement("min");
// if(fg->NextSiblingElement("min") != NULL){
//   cout<<"pzyjazd"<<przyjazd_m<<endl;
// fg->NextSiblingElement("min")->NextSiblingElement("min")->QueryIntAttribute("m", &odjazd_m);
// cout<<"OK "<<przyjazd_m<<endl;}
//
//             roznica = (przyjazd_h - odjazd_h) * 60 + przyjazd_m - odjazd_m;
          }
          czas_przejazdu.push(roznica);
        }
      }

      for (vector<Stop *>::iterator it = tmp_stops.begin();
           it != tmp_stops.end(); ++it) {
        vector<Stop *>::iterator k = it;
        k++;
        if (k == tmp_stops.end()) {
          break;
        }
        // cout<<k->return_stop_name()<<endl;
        string str = nazwa_lini;
        (*it)->add_connection(str, czas_przejazdu.front(), *k);
        czas_przejazdu.pop();
      }
      // SCAL Z AKTUALNYMI PRZYSTANKAMI
      merge_stops_list();
      if (root->NextSiblingElement("wariant") != NULL) {
        root = root->NextSiblingElement("wariant");
        root->QueryIntAttribute("id", &wariant);
      }
      loop++;
    }
  }
}
//////////////////////////////////////
void LoadData::merge_stops_list() {
  // std::sort(stops.begin(), stops.end());
  // std::sort(tmp_stops.begin(), tmp_stops.end());
  vector<Stop *>::iterator it;
  vector<Stop *>::iterator k;
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
        // scal połączenia
        (*k)->mergeConnection((*it)->returnConnection());
      } else {
        stops.push_back(*it);
      }
    }
  }
}

void LoadData::loadLocalizations(const char* file) const
{
    fstream fileStream(file);
    if (!fileStream) return;

    auto reg = regex("(.*),(.*),\"(.*)\",(.*),(.*)");
    std::string line;
    std::getline(fileStream, line); // ingore first line with labels
    while (std::getline(fileStream, line))
    {
    	int id;
    	double x;
    	double y;

    	smatch m;
    	regex_search(line,
        	m,
			reg);

    	id = stoi(m[2]);
    	x = stod(m[4]);
    	y = stod(m[5]);
    	//std::cout << id << "," << x << "," << y << endl;
    	for(auto& e: stops)
    	{
    		//cout << m[3] << e->stop_name << endl;
    		//if(m[3] == e->stop_name)
    		if(id == e->stop_id)
    		{
    			//cout << "i found one!" << endl;
    			e->setLocalization(x, y);
    			continue;
    		}
    	}
    }
}

LoadData::LoadData() {
  std::vector<const char *> array = {
      "data/000p.xml", "data/000l.xml", "data/0001.xml", "data/0002.xml",
      "data/0003.xml", "data/0004.xml", "data/0005.xml", "data/0006.xml",
      "data/0007.xml", "data/0008.xml", "data/0009.xml", "data/0010.xml",
      "data/0011.xml", "data/0014.xml", "data/0015.xml", "data/0017.xml",
      "data/0020.xml", "data/0023.xml", "data/0024.xml", "data/0031.xml",
      "data/0032.xml", "data/0033.xml"};
  int wariant = 1;
  for (int i = 0; i < array.size(); i++) {
    if (i > 1)
      wariant = 2; //  linie poza OL i Op mają więcej niż 1 kierunek jazdy
    createStopsList(array[i], wariant);
  }

  const auto localizationsFile = "data/stops.txt";
     loadLocalizations(localizationsFile);

  cout << "\nUtworzono " << stops.size() << " przystanków" << endl;

  for (vector<Stop *>::iterator it = stops.begin(); it != stops.end(); ++it) {
    if ("Jeleniog�rska" == (*it)->return_stop_name()) {
      (*it)->print_stop_specific();
    }
  }
  for (vector<Stop *>::iterator it = stops.begin(); it != stops.end(); ++it) {
    if ("Nowowiejska" == (*it)->return_stop_name()) {
      (*it)->print_stop_specific();
    }
  }


}

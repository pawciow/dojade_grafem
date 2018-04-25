#include "../hh/gui.hh"


Gui::Gui() {
  startStop = 1;
  goalStop = 10;
  menu();
}

void Gui::findStop(string stop) {
  string scherched = stop;
  string tmp;
  int iter_number = 0;
  bool found = false;

  std::transform(scherched.begin(), scherched.end(), scherched.begin(),
                 ::tolower);

  for (auto i : data->stops) {
    tmp = i->returnStopName();
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    if (tmp.find(scherched) != std::string::npos) {
      found = true;
      cout << "Nazwa: " << i->returnStopName()
           << "\tId przystanu: " << iter_number << '\n';
    }
    iter_number++;
  }
  if (!found)
    cout << "Nie znaleziono przystanku" << endl;
}

void Gui::menu() {
  char choice, choice2;
  bool trasa = true;
;

  DepthFirstSearch DFS(data->stops);
  BreadthFirstSearch BFS(data->stops);
  aStar astar(data->stops);

  string scherch;
  do {
    cout << "\nCo robić?\n(1) Wyświetl id przystanku \n(2) Wybierz początkowy "
            "\n(3) "
            "Wybierz końcowy \n(4) Szukaj trasy \n  " /*(5)Menu graficzne \n*/
            "(9) Wyjście"
         << endl;
    cin >> choice;
    switch (choice) {
    case '1':
     // system("clear");
      cout << "Wpisz fragment nazwy przystanku np: \" grun \"\ndla przystanków "
              "zawierających tą frazę (Pl. Grunwaldzki)"
           << endl;
      cin >> scherch;
      findStop(scherch);
      break;
    case '2':
      cout << "\nPodaj id przystanu początkowego:" << endl;
      cin >> startStop;
      break;
    case '3':
      cout << "\nPodaj id przystanu końcowego:" << endl;
      cin >> goalStop;
      break;
    case '4':
      system("clear");
      cout << "Wybierz algorytm do wyszukiwania:\n (1) DFS (2) BFS (3) A*\n"
           << endl;
      cin >> (choice2);
      switch (choice2) {
      case '1':
        cout << "DFS\nFrom: " << data->stops[startStop]->returnStopName()
             << " To: " << data->stops[goalStop]->returnStopName() << "\n\n";
        DFS.findPath(data->stops[startStop], data->stops[goalStop]);
        break;
      case '2':
          cout << "DFS\nFrom: " << data->stops[startStop]->returnStopName()
               << " To: " << data->stops[goalStop]->returnStopName() << "\n\n";
          BFS.findPath(data->stops[startStop], data->stops[goalStop]);
        break;
      case '3':
        cout << "A*\nFrom: " << data->stops[startStop]->returnStopName()
             << " To: " << data->stops[goalStop]->returnStopName() << "\n\n";
        astar.findPath(data->stops[startStop], data->stops[goalStop]);
        astar.printPath();
        break;
      }
      break;
    /*case '5':
      cout << "\nMenu graficzne: \n(1) Wyświetl przystanki z "
              "połączeniami\n(2) wyświetlaj trasę - on/off"
           << endl;
      cin >> (choice2);
      switch (choice2) {
      case '1':
        cout << "Wyświetlam przystanki\n";
        // jeżeli trasa = true i jeżeli algorytm znalazł trasę
        // to wyplotuj
        break;
      case '2':
        trasa = !trasa;
        cout << "trasa = " << trasa << endl;
        break;
      }
      break;*/
    case '9':
      system("clear");
      cout << "Koniec programu\n\n";
      break;

    default:
      cout << "Zły wybór";
      break;
    }
  } while (choice != '9');
}


#include <algorithm>
#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <vector>
using namespace std;

class Foo {
  int stop_id;

public:
  Foo(int a) { stop_id = a; }
  int return_id() const { return stop_id; }
  void print() { std::cout << "\nWyszukane id: " << stop_id << std::endl; }

  bool operator<(Foo const &r) const { return stop_id < r.return_id(); }

};

bool compareFooById(const Foo &a, const int &b) { return a.return_id() < b; }

int main() {
  std::vector<Foo> vect;

  vect.push_back(10);
  int tmp;

  for (int i = 0; i < 2000; i++) {
    tmp = rand() % 100;
    vect.push_back(tmp);
  }
  int id_to_find = 64;
  std::cout << "Szukane id: " << id_to_find << std::endl;

  std::sort(vect.begin(), vect.end());
  std::vector<Foo>::iterator f;
  for (int j = 0; j < 2000; j++) {
    f = std::lower_bound(vect.begin(), vect.end(), id_to_find, compareFooById);
  }
  f->print();

  return 0;
}

#include "../hh/main.hh"
using namespace std;

int main() {
  cout <<'\n'<< "Start:" << endl;
  LoadData *test = new LoadData();
  test->export_stops_list();
  return 0;
}

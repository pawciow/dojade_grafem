#include "../hh/interfaces.hh"



ostream& operator<<(ostream& out, const IResults results)
{
	out << "Route: " << endl;
	for(auto& e: results.Path)
		out << " Przystanek: " << e.stopName << " Tramwaj " << e.lineName << endl;
	return out;
}




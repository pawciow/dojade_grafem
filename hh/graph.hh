
#include "../hh/loadbinary.hh"
#include <map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph{

};
enum colors
{
	white,
	grey,
	black
};

class IColors
{
protected:
	map<int, colors > nodColors;
};
class IResults
{
protected:
	struct _path
	{
		string lineName;
		string stopName;
		_path(string Line, string Stop)
			{lineName = Line; stopName = lineName;}
	};
	vector<_path> Path;
friend ostream& operator << (ostream& out, const IResults);
};

ostream& operator << (ostream& out, const IResults);

class DFS : private IColors, public IResults
{
public:
	DFS(vector<Stop*> nods);
	void operator() (vector<Stop*> nods);
private:
	void visitNode(Stop*);

};

class BFS : private IColors, private IResults
{
public:
	BFS(vector<Stop> nods, int from);
	void operator() (vector<Stop> nods, int from );
private:
	queue<Stop> Q;

	void Enqueue(vector<Stop>& nods, int from);
};

#pragma once

#include "../model/Graph.h"
#include "../model/Path.h"
#include "../model/Solution.h"
#include "../model/tests/Tests.h"

#include <tuple>
#include <vector>
#include <time.h>

class Presenter {
private:
	Graph* graph;
public:
	void createGraph(int v, int r);
	string getGraph();
	pair<string, string> colorGraph(); // <colored graph, time to color>
	pair<string, string> tspGraph(string way, int begin); // <tsp way, time to color>
	pair<string, string> shortestWay(int begin, int end);
	pair<string, string> backBone(); // <backBone, time>
	string getTests();
};
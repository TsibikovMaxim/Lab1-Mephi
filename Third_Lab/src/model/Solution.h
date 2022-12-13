#pragma once

#include "Graph.h"
#include "Path.h"
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
    Graph graph;

public:
    Solution(Graph& g);
    Path* Dijkstra(int v, Path* data);
    Path calc(vector<int> v, int start);        // calculating the optimal path

};


#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

#include "DisjointSet.h"

using namespace std;

class Graph {
private:
    int countTops;                              // count tops
    int** data;                                 // arc weight
    vector<std::vector<int>> adjList;           // adjacency matrix
    vector<tuple<int,int,int>> edges;           // arc info: begin, end, weight

public:
    Graph();                                    // const graph
    Graph(int v, int r);                        // random generated graph. v - count tops, r - count arc
    Graph(vector<tuple<int,int,int>> vector);   // own entered graph (begin, end, weight)

    int** getData() const;                      // return matrix of weights
    int getCountTops() const;                   // returns tops count
    string printGraph();
    string colorGraph();
    vector<int> bfs(int s, int t);              // shortest way between 2 tops
    vector<tuple<int,int,int>> getOstov();      // return graph ostov
};

ostream& operator<<(ostream& os, const Graph& g);

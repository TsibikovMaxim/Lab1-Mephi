#pragma once

#include "map"

using namespace std;

class DisjointSet {
    map<int, int> parent;

public:
    void makeSet(int n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int k) {
        if (parent[k] == k)
            return k;

        return Find(parent[k]);
    }

    void Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);

        parent[x] = y;
    }
};

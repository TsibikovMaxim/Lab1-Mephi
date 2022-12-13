#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Path {
private:
    vector<int> path;
    int length;

public:
    Path(int start);
    Path& operator= (const Path& p);
    vector<int> getPath() const;
    int getLength() const;
    string toString();
    void push_back(int v, int l);
    void push_back(Path p);
};

ostream& operator<<(ostream& os, const Path& p);

#include "Presenter.h"

vector<int> splitString(string s) {
    vector<int> vec;

    string delimiter = ", ";

    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        vec.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }
    vec.push_back(stoi(s));
    return vec;
}

void Presenter::createGraph(int v, int r) {
    graph = new Graph(v, r);
}

string Presenter::getGraph() {
    return graph->printGraph();
}

pair<string, string> Presenter::colorGraph() {
    string coloredGraph, time;
    clock_t start, end;
    start = clock();

    coloredGraph = graph->colorGraph();

    end = clock();
    time = to_string((int)(end - start) / (CLOCKS_PER_SEC / 1000)) + " ms";

    return make_pair(coloredGraph, time);
}

pair<string, string> Presenter::tspGraph(string way, int begin) {
    string tspWay, time;
    clock_t start, end;
    start = clock();

    Solution s = Solution(*graph);
    tspWay = s.calc(splitString(way), begin).toString();

    end = clock();
    time = to_string((int)(end - start) / (CLOCKS_PER_SEC / 1000)) + " ms";

    return make_pair(tspWay, time);
}

pair<string, string> Presenter::shortestWay(int begin, int end) {
    vector<int> pointsOfWay;
    string shortestWay = "", time;
    clock_t start, finish;
    start = clock();

    pointsOfWay = graph->bfs(begin, end);
    for (int i : pointsOfWay)
        shortestWay += to_string(i) + " ";

    finish = clock();
    time = to_string((int)(finish - start) / (CLOCKS_PER_SEC / 1000)) + " ms";

    return make_pair(shortestWay, time);
}

pair<string, string> Presenter::backBone() {
    string res = "", time;
    clock_t start, finish;
    start = clock();

    vector<tuple<int, int, int>> vec = graph->getOstov();

    for(tuple<int, int, int> tuple : vec)
        res += "(" + to_string(get<0>(tuple)) + ", " +
        to_string(get<1>(tuple)) + ", " +
        to_string(get<2>(tuple)) + ")\n";

    finish = clock();
    time = to_string((int)(finish - start) / (CLOCKS_PER_SEC / 1000)) + " ms";

    return make_pair(res, time);
}

string Presenter::getTests() {
    Tests tests;
    return tests.startAllTests();
}
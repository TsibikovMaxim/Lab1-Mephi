#include "Tests.h"

string ckeck(string s, bool f) {
    if(f)
        return s + " - OK\n";
    return s + " - NO\n";
}

string testColorGraph() {
    Graph graph = Graph();
    string graphColor = "The color assigned to vertex 0 is BLUE\n"
                        "The color assigned to vertex 1 is GREEN\n"
                        "The color assigned to vertex 2 is BLUE\n"
                        "The color assigned to vertex 3 is RED\n"
                        "The color assigned to vertex 4 is GREEN\n";

    bool f = graphColor == graph.colorGraph();
    return ckeck("ColorGraph", f);
}

string testTSP() {
    Graph graph = Graph();
    Solution s = Solution(graph);
    string calculed = s.calc({0,2}, 0).toString();

    bool f = calculed == "1->2->3->2->1 (12)";
    return ckeck("Comivoyager", f);
}

string testShortesWay() {
    Graph graph = Graph();
    vector<int> resBfs = graph.bfs(0,4), vecRes = {0,1,2,4};

    bool f = resBfs == vecRes;
    return  ckeck("ShortesWay", f);
}

string testFindOstov() {
    Graph graph = Graph();
    vector<tuple<int,int,int>> vecOstov = graph.getOstov(), vecRes;
    vecRes.push_back(make_tuple(1, 0, 2));
    vecRes.push_back(make_tuple(3, 0, 3));
    vecRes.push_back(make_tuple(2, 1, 4));
    vecRes.push_back(make_tuple(4, 2, 6));

    bool f = vecOstov == vecRes;
    return  ckeck("FindOstov", f);
}

string Tests::startAllTests() {
    string resTests = "";
    resTests += testColorGraph();
    resTests += testTSP();
    resTests += testShortesWay();
    resTests += testFindOstov();
    return resTests;
}

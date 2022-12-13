#include "Graph.h"

struct compare {
    bool operator() (tuple<int,int,int> const &a, tuple<int,int,int> const &b) const {
        return get<2>(a) > get<2>(b);
    }
};

string color[] = {
        "", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
        "BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"
};

vector<tuple<int,int,int>> runKruskalAlgorithm(vector<tuple<int,int,int>> edges, int n) {
    vector<tuple<int,int,int>> MST;

    DisjointSet ds;
    ds.makeSet(n);
    sort(edges.begin(), edges.end(), compare());

    while (MST.size() != n - 1) {
        tuple<int,int,int> next_edge = edges.back();
        edges.pop_back();

        int x = ds.Find(get<0>(next_edge));
        int y = ds.Find(get<1>(next_edge));

        if (x != y) {
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}

Graph::Graph() {
    this->countTops = 5;
    data = new int*[5];
    for (int i = 0; i < 5; i++)
        data[i] = new int[5];

    data[0][0] = 0;    data[0][1] = 2;    data[0][2] = 0;    data[0][3] = 3;    data[0][4] = 0;
    data[1][0] = 2;     data[1][1] = 0;    data[1][2] = 4;     data[1][3] = 4;    data[1][4] = 0;
    data[2][0] = 0;   data[2][1] = 4;    data[2][2] = 0;     data[2][3] = 5;    data[2][4] = 6;
    data[3][0] = 3;    data[3][1] = 4;    data[3][2] = 5;    data[3][3] = 0;    data[3][4] = 0;
    data[4][0] = 0;   data[4][1] = 0;   data[4][2] = 6;     data[4][3] = 0;   data[4][4] = 0;

    adjList.resize(5);
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(data[i][j] != 0) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
                edges.push_back(make_tuple(i,j,data[i][j]));
            }
}

Graph::Graph(int v, int r) {
    this->countTops = v;
    data = new int*[v];
    for (int i = 0; i < v; i++)
        data[i] = new int[v];

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            data[i][j] = 0;

    adjList.resize(v);
    for(int i = 0; i < r; i++) {
        int start = rand() % v, end = rand() % v;
        if(end == start && end == 0)
            end++;
        if(end == start && end > 0)
            end--;
        int weight = (rand() % 10 + 1) * 5;
        data[start][end] = weight;
        data[end][start] = weight;
        vector<tuple<int,int,int>> vector;
        vector.push_back(make_tuple(start,end,weight));

        edges.push_back(make_tuple(start,end,weight));

        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }

}

Graph::Graph(vector<tuple<int,int,int>> vector) {
    edges = vector;
    this->countTops = vector.size();
    data = new int*[vector.size()];
    for (int i = 0; i < vector.size(); i++)
        data[i] = new int[vector.size()];

    for(int i = 0; i < vector.size(); i++)
        for(int j = 0; j < vector.size(); j++)
            data[i][j] = 0;

    adjList.resize(vector.size());
    for(tuple<int,int,int> tuple: vector) {
        int begin = get<0>(tuple);
        int end = get<1>(tuple);
        int weight = get<2>(tuple);
        data[begin][end] = weight;
        data[end][begin] = weight;

        adjList[begin].push_back(end);
        adjList[end].push_back(begin);
    }
}

int** Graph::getData() const {
    int** d = new int*[countTops];
    for (int i = 0; i < countTops; ++i) {
        d[i] = new int[countTops];
        for (int j = 0; j < countTops; ++j)
            d[i][j] = data[i][j];
    }
    return d;
}

int Graph::getCountTops() const { return countTops; }

string Graph::printGraph() {
    string res = "";
    for(tuple<int,int,int> v: edges)
        res += "(" + to_string(get<0>(v)) + ", " +
                to_string(get<1>(v)) + ", " +
                to_string(get<2>(v)) + ")\n";
    return res;
}

string Graph::colorGraph() {
    string res = "";
    map<int, int> result;
    for (int u = 0; u < getCountTops(); u++) {
        set<int> assigned;

        for (int i: adjList[u])
            if (result[i])
                assigned.insert(result[i]);

        int color = 1;
        for (auto &c: assigned ) {
            if (color != c)
                break;
            color++;
        }

        result[u] = color;
    }

    for (int v = 0; v < getCountTops(); v++)
        res += "The color assigned to vertex " + to_string(v) + " is " + color[result[v]] + "\n";

    return res;
}

vector<int> Graph::bfs(int s, int t) {
    vector<int> dist(countTops, countTops);
    vector<int> p(countTops, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adjList[v]) {
            if (dist[u] > dist[v] + 1) {
                p[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    if (dist[t] == countTops) {
        return {};
    }

    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = p[t];
    }

    reverse(path.begin(), path.end());
    return path;
}

vector<tuple<int,int,int>> Graph::getOstov() {
    vector<tuple<int,int,int>> e = runKruskalAlgorithm(edges, countTops);
    return e;
}

ostream& operator<<(ostream& os, const Graph& g) {
    int** d = g.getData();

    for (int i = 0; i < g.getCountTops(); i++) {
        for (int j = 0; j < g.getCountTops(); j++)
            os << setw(4) << d[i][j] << ' ';
        os << endl;
    }
    return os;
}
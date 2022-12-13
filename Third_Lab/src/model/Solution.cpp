#include "Solution.h"

Solution::Solution(Graph& g) {
    graph = g;
}

Path* Solution::Dijkstra(int v, Path* data) {
    data = (Path*)calloc(graph.getCountTops(), sizeof(Path));
    int* distaces = new int[graph.getCountTops()];
    int* out = new int[graph.getCountTops()];
    for (int i = 0; i < graph.getCountTops(); ++i) {
        if (i == v) {
            distaces[i] = 0;
            data[i] = Path(v);
        } else
            distaces[i] = numeric_limits<int>::max();
        out[i] = 0;
    }

    int min = numeric_limits<int>::max(), index = -1;
    do {
        min = numeric_limits<int>::max();
        for (int i = 0; i < graph.getCountTops(); ++i) {
            if ((out[i] == 0) && (distaces[i] < min)) {
                min = distaces[i];
                index = i;
            }
        }
        if (min != numeric_limits<int>::max()) {
            for (int i = 0; i < graph.getCountTops(); ++i) {
                if (graph.getData()[index][i] > 0) {
                    int temp = min + graph.getData()[index][i];
                    if (temp < distaces[i]) {
                        distaces[i] = temp;
                        data[i] = data[index];
                        data[i].push_back(i, graph.getData()[index][i]);
                    }
                }
            }
            out[index] = 1;
        }
    } while (min < numeric_limits<int>::max());

    return data;
}

Path Solution::calc(vector<int> v, int start) {
    map<int, Path*> distaces;
    Path* temp = (Path*)calloc(graph.getCountTops(), sizeof(Path));
    temp = Dijkstra(start, temp);
    distaces[start] = temp;
    for (size_t i = 0; i < v.size(); ++i) {
        temp = Dijkstra(v[i], temp);
        distaces[v[i]] = temp;
    }

    Path p = Path(start);
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); ++i) {
        int last = p.getPath()[p.getPath().size() - 1];
        p.push_back(distaces[last][v[i]]);
    }
    int last = p.getPath()[p.getPath().size() - 1];
    p.push_back(distaces[last][start]);
    next_permutation(v.begin(), v.end());

    do {
        Path temp = Path(start);
        for (size_t i = 0; i < v.size(); ++i) {
            int last = temp.getPath()[temp.getPath().size() - 1];
            temp.push_back(distaces[last][v[i]]);
            if (temp.getLength() > p.getLength())
                break;
        }
        int last = temp.getPath()[temp.getPath().size() - 1];
        temp.push_back(distaces[last][start]);

        if (temp.getLength() < p.getLength()) {
            p = temp;
        }
    } while (next_permutation(v.begin(), v.end()));

    return p;
}
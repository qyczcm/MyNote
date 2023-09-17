#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w, p;
};

int find(vector<int>& parent, int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);
    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

pair<vector<Edge>, int> kruskal(vector<Edge>& edges, int n) {
    vector<Edge> selectedEdges;
    int totalCost = 0;
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    int selected = 0;
    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        int p = edge.p;

        if (find(parent, u) != find(parent, v)) {
            unionSet(parent, rank, u, v);
            selectedEdges.push_back(edge);
            totalCost += w;
            if (p == 1) {
                selected++;
            }
        }
    }

    if (selectedEdges.size() != n-1 || selected != 2) {
        return make_pair(vector<Edge>(), -1);
    }

    return make_pair(selectedEdges, totalCost);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w >> edges[i].p;
    }

    pair<vector<Edge>, int> result = kruskal(edges, n);
    if (result.second == -1) {
        cout << -1 << endl;
    } else {
        cout << result.first.size() << endl;
        for (const auto& edge : result.first) {
            cout << edge.u << " " << edge.v << " " << edge.w << endl;
        }
        cout << result.second << endl;
    }

    return 0;
}

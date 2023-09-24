#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

void dfs(int node, int parent, int depth, vector<vector<int>>& edges, vector<int>& colors, unordered_map<int, vector<int>>& colorDict, int& minDistance) {
    int color = colors[node - 1];  // 当前节点的颜色
    if (colorDict.find(color) != colorDict.end() && colorDict[color].size() >= 2) {
        // 如果当前颜色的节点列表中至少有两个节点，计算它们之间的最小距离
        
        vector<int> nodes = colorDict[color];
        int distance = abs(nodes[0] - nodes[1]) + depth;
        minDistance = min(minDistance, distance);
    }

    for (int neighbor : edges[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, depth + 1, edges, colors, colorDict, minDistance);
        }
    }
}

int findClosestDistance(int n, int m, vector<int>& colors, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> colorDict;
    for (int i = 0; i < n; i++) {
        int color = colors[i];
        if (colorDict.find(color) == colorDict.end()) {
            colorDict[color] = vector<int>();
        }
        colorDict[color].push_back(i + 1);  // 节点从1开始编号
    }

    int minDistance = INT_MAX;  // 初始化最小距离为最大值

    dfs(1, -1, 0, edges, colors, colorDict, minDistance);

    if (minDistance == INT_MAX) {
        return -1;
    } else {
        return minDistance;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int result = findClosestDistance(n, m, colors, edges);
    cout << result << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj_list, vector<int>& path_len, vector<int>& exit_count) {
    // 基本情况: 该节点为叶子节点，即没有儿子节点
    if (adj_list[node].empty()) {
        exit_count[node] = 1;  // 当前节点为出口
        return;
    }

    for (int child : adj_list[node]) {
        path_len[child] = path_len[node] + 1;  // 记录从根节点到当前节点的路径长度
        dfs(child, adj_list, path_len, exit_count);
        exit_count[node] += exit_count[child];  // 累计当前节点的出口个数
    }
}

int main() {
    int n, m, g;
    cin >> n >> m >> g;

    vector<vector<int>> adj_list(n + 1);
    vector<int> path_len(n + 1, 0);
    vector<int> exit_count(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    dfs(1, adj_list, path_len, exit_count);
    for (int i = 0; i < g; i++) {
        int query;
        cin >> query;        
        cout << exit_count[query] << endl;
    }

    return 0;
}

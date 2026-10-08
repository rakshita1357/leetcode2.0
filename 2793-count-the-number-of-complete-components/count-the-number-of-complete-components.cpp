class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited,
             int& edge, int& nodes) {

        visited[node] = true;
        nodes++;
        edge += graph[node].size();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited, edge, nodes);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> AL(n);
        int ans = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                int nodes = 0;
                int edges = 0;

                dfs(i, AL, visited, edges, nodes);

                edges /= 2;

                if (edges == nodes * (nodes - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
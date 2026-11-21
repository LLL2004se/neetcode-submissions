class Solution {
public:

    void dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        visited[node] = true;

        for(int neighbor : adj[node]) {

            if(!visited[neighbor]) {
                dfs(neighbor, node, adj, visited);
            }
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree must have exactly n-1 edges
        if(edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        // Build undirected graph
        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // Start DFS from node 0
        dfs(0, -1, adj, visited);

        // Check whether all nodes are visited
        for(int i = 0; i < n; i++) {

            if(!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
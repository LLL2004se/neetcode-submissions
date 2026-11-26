
class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {

        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1, 0);

        for (auto& c : conditions) {
            adj[c[0]].push_back(c[1]);
            indegree[c[1]]++;
        }

        queue<int> q;

        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() != k) return {};

        return order;
    }

    vector<vector<int>> buildMatrix(
        int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions
    ) {

        vector<int> row = topoSort(k, rowConditions);
        vector<int> col = topoSort(k, colConditions);

        if (row.empty() || col.empty()) return {};

        vector<vector<int>> ans(k, vector<int>(k, 0));

        vector<int> rowPos(k + 1), colPos(k + 1);

        for (int i = 0; i < k; i++) {
            rowPos[row[i]] = i;
            colPos[col[i]] = i;
        }

        for (int i = 1; i <= k; i++) {
            ans[rowPos[i]][colPos[i]] = i;
        }

        return ans;
    }
};

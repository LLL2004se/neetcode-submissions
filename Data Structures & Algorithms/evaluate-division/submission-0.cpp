
class Solution {
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];

            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0 / values[i]});
        }

        vector<double> ans;

        for (auto& q : queries) {
            string src = q[0];
            string dest = q[1];

            if (!adj.count(src) || !adj.count(dest)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            queue<pair<string, double>> qu;
            qu.push({src, 1.0});
            visited.insert(src);

            double result = -1.0;

            while (!qu.empty()) {
                auto [node, product] = qu.front();
                qu.pop();

                if (node == dest) {
                    result = product;
                    break;
                }

                for (auto& [neighbor, weight] : adj[node]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        qu.push({neighbor, product * weight});
                    }
                }
            }

            ans.push_back(result);
        }

        return ans;
    }
};

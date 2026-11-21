
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times,
                         int n, int k) {

        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &t : times) {

            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v, w});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);

        // Min heap: {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        // Dijkstra
        while(!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if(d > dist[node]) {
                continue;
            }

            for(auto [neighbor, weight] : adj[node]) {

                int newDist = d + weight;

                if(newDist < dist[neighbor]) {

                    dist[neighbor] = newDist;

                    pq.push({newDist, neighbor});
                }
            }
        }

        // Find maximum shortest distance
        int ans = 0;

        for(int i = 1; i <= n; i++) {

            if(dist[i] == INT_MAX) {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};

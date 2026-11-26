
class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);

        return parent[x];
    }

    bool unite(int x, int y, vector<int>& parent, vector<int>& rank) {
        x = find(x, parent);
        y = find(y, parent);

        if (x == y) return false;

        if (rank[x] < rank[y]) swap(x, y);

        parent[y] = x;

        if (rank[x] == rank[y])
            rank[x]++;

        return true;
    }

    int kruskal(int n, vector<vector<int>>& edges, int skip, int pick) {
        vector<int> parent(n), rank(n, 0);

        iota(parent.begin(), parent.end(), 0);

        int cost = 0;
        int count = 0;

        if (pick != -1) {
            auto& e = edges[pick];

            if (unite(e[0], e[1], parent, rank)) {
                cost += e[2];
                count++;
            }
        }

        for (int i = 0; i < edges.size(); i++) {

            if (i == skip || i == pick) continue;

            auto& e = edges[i];

            if (unite(e[0], e[1], parent, rank)) {
                cost += e[2];
                count++;
            }
        }

        return count == n - 1 ? cost : INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n, vector<vector<int>>& edges
    ) {
        int m = edges.size();

        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        int minCost = kruskal(n, edges, -1, -1);

        vector<int> critical, pseudo;

        for (int i = 0; i < m; i++) {

            int without = kruskal(n, edges, i, -1);

            if (without > minCost) {
                critical.push_back(edges[i][3]);
            }
            else {
                int with = kruskal(n, edges, -1, i);

                if (with == minCost) {
                    pseudo.push_back(edges[i][3]);
                }
            }
        }

        return {critical, pseudo};
    }
};

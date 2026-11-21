
class Solution {
public:

    vector<int> parent;
    vector<int> size;

    // Find with path compression
    int find(int x) {

        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    // Union by size
    void unite(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if(pu == pv) {
            return;
        }

        if(size[pu] < size[pv]) {
            swap(pu, pv);
        }

        parent[pv] = pu;
        size[pu] += size[pv];
    }

    vector<int> findRedundantConnection(
        vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        size.assign(n + 1, 1);

        // Initially every node is its own parent
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        // Process every edge
        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            // Already connected = cycle
            if(find(u) == find(v)) {
                return {u, v};
            }

            unite(u, v);
        }

        return {};
    }
};


class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (sz[x] < sz[y])
            swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
    }

    bool canTraverseAllPairs(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return true;

        for (int x : nums) {
            if (x == 1) return false;
        }

        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, int> factorOwner;

        for (int i = 0; i < n; i++) {

            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {

                if (x % p == 0) {

                    if (factorOwner.count(p)) {
                        unite(i, factorOwner[p]);
                    } else {
                        factorOwner[p] = i;
                    }

                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }

            if (x > 1) {

                if (factorOwner.count(x)) {
                    unite(i, factorOwner[x]);
                } else {
                    factorOwner[x] = i;
                }
            }
        }

        int root = find(0);

        for (int i = 1; i < n; i++) {
            if (find(i) != root)
                return false;
        }

        return true;
    }
};

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            vector<int> sum(n, 0);

            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    sum[k] += matrix[j][k];
                }

                unordered_map<int, int> mp;
                mp[0] = 1;
                int prefix = 0;

                for (int x : sum) {
                    prefix += x;
                    ans += mp[prefix - target];
                    mp[prefix]++;
                }
            }
        }

        return ans;
    }
};
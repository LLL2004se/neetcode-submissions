class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long top = 0, bottom = 0;

        for (int num : grid[0]) {
            top += num;
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < grid[0].size(); i++) {
            top -= grid[0][i];

            ans = min(ans, max(top, bottom));

            bottom += grid[1][i];
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n * n + 1, 0);

        for (auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        int a = -1, b = -1;

        for (int i = 1; i <= n * n; i++) {
            if (freq[i] == 2) a = i;
            if (freq[i] == 0) b = i;
        }

        return {a, b};
    }
};
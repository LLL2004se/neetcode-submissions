class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        int maxGap = 0;

        for (auto& row : wall) {
            int sum = 0;

            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                mp[sum]++;
                maxGap = max(maxGap, mp[sum]);
            }
        }

        return wall.size() - maxGap;
    }
};
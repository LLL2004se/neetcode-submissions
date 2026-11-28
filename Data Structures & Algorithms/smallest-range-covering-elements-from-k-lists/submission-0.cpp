class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int maxVal = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            maxVal = max(maxVal, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int minVal = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (maxVal - minVal < end - start) {
                start = minVal;
                end = maxVal;
            }

            if (col + 1 == nums[row].size()) {
                break;
            }

            int nextVal = nums[row][col + 1];
            maxVal = max(maxVal, nextVal);

            pq.push({nextVal, row, col + 1});
        }

        return {start, end};
    }
};
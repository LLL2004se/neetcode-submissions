class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0, leftSum = 0;
        int ans = 0;

        for (int num : nums) {
            total += num;
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            total -= nums[i];

            if (leftSum >= total) {
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], cur = nums[0]; for (int i = 1; i < nums.size(); i++) best = max(best, cur = max(nums[i], cur + nums[i])); return best;
// 88 Merge Sorted Array
    }
};
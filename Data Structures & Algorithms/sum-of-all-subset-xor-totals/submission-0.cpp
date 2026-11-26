
class Solution {
public:
    int solve(vector<int>& nums, int index, int currXor) {
        if (index == nums.size()) {
            return currXor;
        }

        // Include current element
        int include = solve(nums, index + 1, currXor ^ nums[index]);

        // Exclude current element
        int exclude = solve(nums, index + 1, currXor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};

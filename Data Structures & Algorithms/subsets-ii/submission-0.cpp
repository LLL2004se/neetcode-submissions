class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        backtrack(0, nums, temp, ans);

        return ans;
    }

    void backtrack(int index, vector<int>& nums,
                   vector<int>& temp,
                   vector<vector<int>>& ans) {

        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            temp.push_back(nums[i]);

            backtrack(i + 1, nums, temp, ans);

            temp.pop_back();
        }
    }
};
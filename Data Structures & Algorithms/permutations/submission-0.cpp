class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        backtrack(nums, temp, used, ans);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<int>& temp,
                   vector<bool>& used,
                   vector<vector<int>>& ans) {

        // All elements are selected
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Skip already used elements
            if (used[i]) {
                continue;
            }

            // Choose
            temp.push_back(nums[i]);
            used[i] = true;

            // Explore
            backtrack(nums, temp, used, ans);

            // Backtrack (Undo choice)
            temp.pop_back();
            used[i] = false;
        }
    }
};
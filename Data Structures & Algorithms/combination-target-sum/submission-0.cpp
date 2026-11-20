class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(0, candidates, target, temp, ans);

        return ans;
    }

    void backtrack(int index, vector<int>& candidates, int target,
                   vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (index >= candidates.size() || target < 0) {
            return;
        }

        // Pick the current element
        temp.push_back(candidates[index]);

        // Same index because reuse is allowed
        backtrack(index, candidates, target - candidates[index], temp, ans);

        // Backtrack
        temp.pop_back();

        // Skip the current element
        backtrack(index + 1, candidates, target, temp, ans);
    }
};
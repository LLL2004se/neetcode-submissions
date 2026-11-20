class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, target, temp, ans);

        return ans;
    }

    void backtrack(int index, vector<int>& candidates, int target,
                   vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            temp.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            backtrack(i + 1, candidates, target - candidates[i], temp, ans);

            temp.pop_back();
        }
    }
};
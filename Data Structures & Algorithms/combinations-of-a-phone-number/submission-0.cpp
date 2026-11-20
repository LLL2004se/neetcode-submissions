class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> mapping = {
            "",     "",     "abc",  "def",
            "ghi",  "jkl",  "mno",  "pqrs",
            "tuv",  "wxyz"
        };

        vector<string> ans;
        string temp;

        backtrack(0, digits, mapping, temp, ans);

        return ans;
    }

    void backtrack(int index, string& digits,
                   vector<string>& mapping,
                   string& temp,
                   vector<string>& ans) {

        // All digits processed
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        // Get letters corresponding to current digit
        string letters = mapping[digits[index] - '0'];

        for (char ch : letters) {

            // Choose
            temp.push_back(ch);

            // Explore next digit
            backtrack(index + 1, digits, mapping, temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }
};
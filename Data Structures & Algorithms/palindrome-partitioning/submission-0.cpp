class Solution {
public:
    vector<vector<string>> ans;

    vector<vector<string>> partition(string s) {
        vector<string> temp;

        backtrack(0, s, temp);

        return ans;
    }

    void backtrack(int index, string& s, vector<string>& temp) {

        // Entire string has been partitioned
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {

            if (isPalindrome(s, index, i)) {

                // Choose
                temp.push_back(s.substr(index, i - index + 1));

                // Explore
                backtrack(i + 1, s, temp);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
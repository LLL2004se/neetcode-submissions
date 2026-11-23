class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end()); return string(strs[0].begin(), mismatch(strs[0].begin(), strs[0].end(), strs.back().begin()).first);

    }
};
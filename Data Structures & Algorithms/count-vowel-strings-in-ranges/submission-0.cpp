class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' ||
                   c == 'o' || c == 'u';
        };

        for (int i = 0; i < n; i++) {
            int len = words[i].size();

            prefix[i + 1] = prefix[i];

            if (isVowel(words[i][0]) && isVowel(words[i][len - 1])) {
                prefix[i + 1]++;
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            ans.push_back(prefix[q[1] + 1] - prefix[q[0]]);
        }

        return ans;
    }
};
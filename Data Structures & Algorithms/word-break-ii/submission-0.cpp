
class Solution {
public:
    unordered_map<string, vector<string>> dp;

    vector<string> solve(string s, unordered_set<string>& dict) {

        if (dp.count(s))
            return dp[s];

        vector<string> ans;

        if (s.empty()) {
            ans.push_back("");
            return ans;
        }

        for (int i = 1; i <= s.size(); i++) {

            string word = s.substr(0, i);

            if (dict.find(word) != dict.end()) {

                vector<string> rest = solve(s.substr(i), dict);

                for (string sentence : rest) {

                    if (sentence.empty())
                        ans.push_back(word);

                    else
                        ans.push_back(word + " " + sentence);
                }
            }
        }

        return dp[s] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return solve(s, dict);
    }
};

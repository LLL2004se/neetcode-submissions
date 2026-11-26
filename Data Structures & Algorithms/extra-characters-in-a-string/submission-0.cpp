
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();

        unordered_set<string> st(dictionary.begin(), dictionary.end());

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Consider current character as extra
            dp[i] = dp[i - 1] + 1;

            // Check all possible previous substrings
            for (int j = 0; j < i; j++) {

                string sub = s.substr(j, i - j);

                if (st.count(sub)) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};

class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> dp(1 << n, 0);

        for (int mask = 1; mask < (1 << n); mask++) {
            string t = "";

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    t += s[i];
                }
            }

            string rev = t;
            reverse(rev.begin(), rev.end());

            if (t == rev) {
                dp[mask] = __builtin_popcount(mask);
            }
        }

        for (int i = 1; i < (1 << n); i++) {
            if (dp[i] == 0) continue;

            for (int j = i + 1; j < (1 << n); j++) {
                if (dp[j] == 0) continue;

                if ((i & j) == 0) {
                    ans = max(ans, dp[i] * dp[j]);
                }
            }
        }

        return ans;
    }
};
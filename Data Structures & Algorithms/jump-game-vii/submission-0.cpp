
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        int reachable = 0;

        for (int i = 1; i < n; i++) {
            int add = i - minJump;
            int remove = i - maxJump - 1;

            if (add >= 0 && dp[add]) reachable++;
            if (remove >= 0 && dp[remove]) reachable--;

            if (s[i] == '0' && reachable > 0) {
                dp[i] = 1;
            }
        }

        return dp[n - 1];
    }
};

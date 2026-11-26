class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        n--;

        for (int i = 0; n > 0; i++) {
            if (((long long)x & (1LL << i)) == 0) {
                if (n & 1) {
                    ans |= (1LL << i);
                }
                n >>= 1;
            }
        }

        return ans;
    }
};
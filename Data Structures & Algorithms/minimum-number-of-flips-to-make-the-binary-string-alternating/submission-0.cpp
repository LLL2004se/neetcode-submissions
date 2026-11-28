class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ans = n;
        int diff1 = 0, diff2 = 0;

        for (int i = 0; i < 2 * n; i++) {
            char c = s[i % n];

            if (c != (i % 2 == 0 ? '0' : '1')) diff1++;
            if (c != (i % 2 == 0 ? '1' : '0')) diff2++;

            if (i >= n) {
                char old = s[(i - n) % n];

                if (old != ((i - n) % 2 == 0 ? '0' : '1')) diff1--;
                if (old != ((i - n) % 2 == 0 ? '1' : '0')) diff2--;
            }

            if (i >= n - 1) {
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};
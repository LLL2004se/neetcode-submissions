class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        for (int x : count) {
            if (x < k) return -1;
        }

        int left = 0, maxLen = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']--;

            while (count[s[right] - 'a'] < k) {
                count[s[left] - 'a']++;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return n - maxLen;
    }
};
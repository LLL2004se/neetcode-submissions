class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int end = 0;

        auto expand = [&](int left, int right) {

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }

            return right - left - 1;
        };


        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            int len1 = expand(i, i);

            // Even length palindrome
            int len2 = expand(i, i + 1);

            int len = max(len1, len2);


            if (len > end - start) {

                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }


        return s.substr(start, end - start + 1);
    }
};
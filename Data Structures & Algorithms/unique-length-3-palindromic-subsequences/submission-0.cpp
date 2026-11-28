class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.find(c);
            int last = s.rfind(c);

            if (first != string::npos && last - first > 1) {
                unordered_set<char> st;

                for (int i = first + 1; i < last; i++) {
                    st.insert(s[i]);
                }

                ans += st.size();
            }
        }

        return ans;
    }
};
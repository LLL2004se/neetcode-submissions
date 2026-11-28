class Solution {
public:
    int minLength(string s) {
        string st;

        for (char c : s) {
            st.push_back(c);

            int n = st.size();

            if (n >= 2 && 
                ((st[n - 2] == 'A' && st[n - 1] == 'B') ||
                 (st[n - 2] == 'C' && st[n - 1] == 'D'))) {
                st.pop_back();
                st.pop_back();
            }
        }

        return st.size();
    }
};
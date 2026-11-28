class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string s = "L" + dominoes + "R";
        string ans = "";

        int j = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '.') continue;

            int middle = i - j - 1;

            if (j > 0) ans += s[j];

            if (s[j] == s[i]) {
                ans += string(middle, s[i]);
            }
            else if (s[j] == 'R' && s[i] == 'L') {
                ans += string(middle / 2, 'R');
                if (middle % 2 == 1) ans += '.';
                ans += string(middle / 2, 'L');
            }
            else {
                ans += string(middle, '.');
            }

            j = i;
        }

        return ans;
    }
};
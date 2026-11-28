class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1), ss2(sentence2);
        vector<string> a, b;
        string word;

        while (ss1 >> word) a.push_back(word);
        while (ss2 >> word) b.push_back(word);

        int i = 0, j = 0;
        int n = a.size(), m = b.size();

        while (i < n && i < m && a[i] == b[i]) {
            i++;
        }

        while (j < n - i && j < m - i &&
               a[n - 1 - j] == b[m - 1 - j]) {
            j++;
        }

        return i + j == min(n, m);
    }
};
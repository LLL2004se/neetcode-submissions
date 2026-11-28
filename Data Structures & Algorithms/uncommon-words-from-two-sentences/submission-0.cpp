class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        vector<string> ans;

        stringstream ss1(s1), ss2(s2);
        string word;

        while (ss1 >> word) {
            freq[word]++;
        }

        while (ss2 >> word) {
            freq[word]++;
        }

        for (auto& [word, count] : freq) {
            if (count == 1) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
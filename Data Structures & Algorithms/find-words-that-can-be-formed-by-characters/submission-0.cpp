class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26] = {0};

        for (char c : chars) {
            freq[c - 'a']++;
        }

        int ans = 0;

        for (string word : words) {
            int temp[26] = {0};
            bool valid = true;

            for (char c : word) {
                temp[c - 'a']++;

                if (temp[c - 'a'] > freq[c - 'a']) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += word.size();
            }
        }

        return ans;
    }
};

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        vector<int> position(26);

        // Store alien character positions
        for (int i = 0; i < 26; i++) {
            position[order[i] - 'a'] = i;
        }

        // Compare adjacent words
        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int j = 0;

            while (j < s1.size() && j < s2.size()) {

                if (s1[j] != s2[j]) {

                    if (position[s1[j] - 'a'] >
                        position[s2[j] - 'a']) {
                        return false;
                    }

                    break;
                }

                j++;
            }

            // Handle prefix condition
            if (j == s2.size() && s1.size() > s2.size()) {
                return false;
            }
        }

        return true;
    }
};

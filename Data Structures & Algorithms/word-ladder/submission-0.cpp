
class Solution {
public:

    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(
            wordList.begin(), wordList.end()
        );

        // Target must exist in dictionary
        if(st.find(endWord) == st.end()) {
            return 0;
        }

        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        // Mark starting word visited
        st.erase(beginWord);

        while(!q.empty()) {

            auto [word, steps] = q.front();
            q.pop();

            // Target found
            if(word == endWord) {
                return steps;
            }

            // Change every character
            for(int i = 0; i < word.size(); i++) {

                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // Check whether generated word exists
                    if(st.find(word) != st.end()) {

                        q.push({word, steps + 1});

                        // Mark visited
                        st.erase(word);
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        return 0;
    }
};

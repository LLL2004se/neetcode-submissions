class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        auto count = [&](int k) -> long long {
            if (k < 0) return 0;

            long long ans = 0;
            int left = 0, consonants = 0;
            unordered_map<char, int> vowels;

            for (int right = 0; right < word.size(); right++) {
                char c = word[right];

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vowels[c]++;
                } else {
                    consonants++;
                }

                while (vowels.size() == 5 && consonants >= k) {
                    ans += word.size() - right;

                    char ch = word[left++];

                    if (vowels.count(ch)) {
                        vowels[ch]--;
                        if (vowels[ch] == 0) {
                            vowels.erase(ch);
                        }
                    } else {
                        consonants--;
                    }
                }
            }

            return ans;
        };

        return count(k) - count(k + 1);
    }
};
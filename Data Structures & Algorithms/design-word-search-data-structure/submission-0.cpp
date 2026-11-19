
class WordDictionary {
private:
    struct Node {
        Node* links[26];
        bool flag;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            flag = false;
        }
    };

    Node* root;

    bool dfs(string &word, int index, Node* node) {
        if (index == word.size()) {
            return node->flag;
        }

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] != nullptr) {
                    if (dfs(word, index + 1, node->links[i])) {
                        return true;
                    }
                }
            }
            return false;
        }

        int pos = ch - 'a';

        if (node->links[pos] == nullptr) {
            return false;
        }

        return dfs(word, index + 1, node->links[pos]);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->links[index] == nullptr) {
                node->links[index] = new Node();
            }

            node = node->links[index];
        }

        node->flag = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

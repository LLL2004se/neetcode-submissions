
class Solution {
private:
    struct Node {
        Node* links[26];
        string word;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            word = "";
        }
    };

    Node* root = new Node();

    void insert(string& word) {
        Node* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->links[index] == nullptr) {
                node->links[index] = new Node();
            }

            node = node->links[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             Node* node, vector<string>& ans) {

        char ch = board[i][j];
        int index = ch - 'a';

        if (node->links[index] == nullptr) {
            return;
        }

        node = node->links[index];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";  // Avoid duplicates
        }

        board[i][j] = '#';  // Mark visited

        int m = board.size();
        int n = board[0].size();

        if (i > 0 && board[i - 1][j] != '#')
            dfs(board, i - 1, j, node, ans);

        if (i < m - 1 && board[i + 1][j] != '#')
            dfs(board, i + 1, j, node, ans);

        if (j > 0 && board[i][j - 1] != '#')
            dfs(board, i, j - 1, node, ans);

        if (j < n - 1 && board[i][j + 1] != '#')
            dfs(board, i, j + 1, node, ans);

        board[i][j] = ch;  // Backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string& word : words) {
            insert(word);
        }

        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};

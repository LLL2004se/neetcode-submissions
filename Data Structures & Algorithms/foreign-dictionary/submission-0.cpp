
class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Identify all characters
        for (string &word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string &w1 = words[i];
            string &w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {

                if (w1[j] != w2[j]) {

                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';

                    if (!adj[u].count(v)) {
                        adj[u].insert(v);
                        indegree[v]++;
                    }

                    found = true;
                    break;
                }
            }

            // Invalid prefix
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        // Topological Sort
        queue<int> q;

        int totalChars = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                totalChars++;

                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        string result = "";

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            result += char(u + 'a');

            for (int v : adj[u]) {

                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Cycle detection
        if (result.size() != totalChars) {
            return "";
        }

        return result;
    }
};

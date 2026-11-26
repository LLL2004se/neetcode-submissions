
class Solution {
public:

    void dfs(
        string email,
        unordered_map<string, vector<string>>& adj,
        unordered_set<string>& visited,
        vector<string>& component
    ) {

        visited.insert(email);
        component.push_back(email);

        for (string neighbor : adj[email]) {

            if (!visited.count(neighbor)) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {

        unordered_map<string, vector<string>> adj;
        unordered_map<string, string> owner;

        // Step 1: Build graph
        for (auto& account : accounts) {

            string name = account[0];
            string firstEmail = account[1];

            for (int i = 1; i < account.size(); i++) {

                string email = account[i];

                owner[email] = name;

                adj[firstEmail].push_back(email);
                adj[email].push_back(firstEmail);
            }
        }

        unordered_set<string> visited;

        vector<vector<string>> ans;

        // Step 2: Find connected components
        for (auto& [email, name] : owner) {

            if (visited.count(email)) {
                continue;
            }

            vector<string> component;

            dfs(email, adj, visited, component);

            // Step 3: Sort emails
            sort(component.begin(), component.end());

            // Step 4: Add name
            vector<string> merged;

            merged.push_back(name);

            for (string e : component) {
                merged.push_back(e);
            }

            ans.push_back(merged);
        }

        return ans;
    }
};

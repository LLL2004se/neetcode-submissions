
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == NULL) return;

            ans.push_back(node->val);
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return ans;
    }
};

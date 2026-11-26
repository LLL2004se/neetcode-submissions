
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == NULL) return;

            dfs(node->left);
            ans.push_back(node->val);
            dfs(node->right);
        };

        dfs(root);
        return ans;
    }
};

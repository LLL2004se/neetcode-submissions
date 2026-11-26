
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (node == NULL) return;

            dfs(node->left);
            dfs(node->right);
            ans.push_back(node->val);
        };

        dfs(root);
        return ans;
    }
};

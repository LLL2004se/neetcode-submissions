
class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Maximum path passing through current node
        maxSum = max(maxSum, root->val + left + right);

        // Return the maximum one-sided path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

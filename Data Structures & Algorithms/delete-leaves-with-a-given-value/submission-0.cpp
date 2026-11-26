
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        if (root == NULL) {
            return NULL;
        }

        // Delete left subtree
        root->left = removeLeafNodes(root->left, target);

        // Delete right subtree
        root->right = removeLeafNodes(root->right, target);

        // Check whether current node is a target leaf
        if (root->left == NULL &&
            root->right == NULL &&
            root->val == target) {

            return NULL;
        }

        return root;
    }
};

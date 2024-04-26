/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        if (root->left == nullptr && root->right == nullptr) {
            return root;
        } else {  // if at least one of the childs exists
            switchChilds(&root->left, &root->right);
            invertTree(root->left);
            invertTree(root->right);
        }

        return root;
    }
private:
    inline void switchChilds(TreeNode **left, TreeNode **right) {
        TreeNode *temp = *left;
        *left = *right;
        *right = temp;
    }
};


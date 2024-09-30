/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or equals to either p or q
        if (!root || root == p || root == q) {
            return root;
        }
        
        // Recursively search in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both sides returned non-null, this is the LCA
        if (left && right) {
            return root;
        }
        
        // Otherwise return the non-null side (could be either left or right)
        return left ? left : right;
    }
};


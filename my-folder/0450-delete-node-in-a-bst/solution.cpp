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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);  // Corrected this line
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor
            TreeNode* temp = inorderSuccessor(root->right);
            root->val = temp->val; // Copy the inorder successor's value to this node
            root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
        }
        return root;
    }

private:
    TreeNode* inorderSuccessor(TreeNode* root) {
        TreeNode* curr = root;
        while (curr && curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }
};


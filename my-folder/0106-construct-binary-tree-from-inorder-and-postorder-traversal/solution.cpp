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
    map<int, int> inMap;  // Map to store the index of each value in inorder
    int postorderIndex;   // Index for postorder traversal
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Populate the inorder index map
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        postorderIndex = postorder.size() - 1; // Initialize postorder index
        return arrayToTree(postorder, 0, postorder.size() - 1);
    }

    TreeNode* arrayToTree(vector<int>& postorder, int left, int right) {
        // Base case: if there are no elements to construct the tree
        if (left > right) {
            return nullptr;
        }

        // Get the root value from the postorder array
        int rootValue = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootValue);

        // Find the index of the root in inorder
        int inRootIndex = inMap[rootValue];

        // Build the right and left subtrees
        // Note: We build the right subtree first because of postorder
        root->right = arrayToTree(postorder, inRootIndex + 1, right);
        root->left = arrayToTree(postorder, left, inRootIndex - 1);
        
        return root;
    }
};

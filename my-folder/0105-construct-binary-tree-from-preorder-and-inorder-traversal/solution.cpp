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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the index of each value in inorder
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        preorderIndex = 0; // Initialize the preorder index
        return arrayToTree(preorder, 0, preorder.size() - 1);
    }

private:
    map<int, int> inMap;
    int preorderIndex;

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // Base case: if there are no elements to construct the tree
        if (left > right) {
            return NULL;
        }
        
        // Get the root value from the preorder array
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        
        // Build the left and right subtrees
        root->left = arrayToTree(preorder, left, inMap[rootValue] - 1);
        root->right = arrayToTree(preorder, inMap[rootValue] + 1, right);
        
        return root;
    }
};

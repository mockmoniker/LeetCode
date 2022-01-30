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
    vector<int> retVect = {};
    
    void travTree(TreeNode* node){
        if(NULL == node) return;
        
        travTree(node->left);
        retVect.push_back(node->val);
        travTree(node->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        travTree(root);
        return retVect;
    }
};
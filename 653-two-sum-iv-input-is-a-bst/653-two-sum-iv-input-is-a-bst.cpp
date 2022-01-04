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
    unordered_map<int, int> umap;
    int i;
    bool valid;
    
    void travTree1(TreeNode* node){
        if(node->left){
            travTree1(node->left);
        }
        if(node->right){
            travTree1(node->right);
        }
        umap.insert({node->val, i++});
        
    }
    
    void travTree2(TreeNode* node, int k){
        if(node->left){
            travTree2(node->left, k);
        }
        if(node->right){
            travTree2(node->right, k);
        }
        if(umap.count(k-node->val) and node->val*2 != k){
            valid = true;
        }
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        valid = false;
        i = 0;
        travTree1(root);
        i = 0;
        travTree2(root, k);
        return valid;
    }
};
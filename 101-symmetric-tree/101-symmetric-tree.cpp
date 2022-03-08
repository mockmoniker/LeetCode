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
    
    bool result = true;
    
public:
    
    void myfunc(TreeNode* lroot, TreeNode* rroot){
        if(lroot->val != rroot->val){
            result = false;
            return;
        }
        
        if(lroot->left and !rroot->right or !lroot->left and rroot->right){
            result = false;
            return;
        }
        
        if(lroot->right and !rroot->left or !lroot->right and rroot->left){
            result = false;
            return;
        }
        
        if(lroot->left){
            myfunc(lroot->left, rroot->right);
        }
        
        if(lroot->right){
            myfunc(lroot->right, rroot->left);
        }
        
        return;
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root->left and !root->right){
            return true;
        }
        
        if(!root->left or !root->right){
            return false;
        }
        
        myfunc(root->left, root->right);
        
        return result;
    }
};
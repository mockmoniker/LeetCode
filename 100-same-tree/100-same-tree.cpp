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
    
    bool result = true;
    
    void myfunc(TreeNode* curr1, TreeNode* curr2){
        if(curr1->val != curr2->val){
            result = false;
            return;
        }
        
        if(curr1->left and !curr2->left or !curr1->left and curr2->left){
            result = false;
            return;
        }
        
        if(curr1->right and !curr2->right or !curr1->right and curr2->right){
            result = false;
            return;
        }
        
        if(curr1->left){
            myfunc(curr1->left, curr2->left);
        }
        
        if(curr1->right){
            myfunc(curr1->right, curr2->right);
        }
        
        return;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q){
            return true;
        }
        
        if(!p or !q){
            return false;
        }
        
        myfunc(p, q);
        
        return result;
    }
};
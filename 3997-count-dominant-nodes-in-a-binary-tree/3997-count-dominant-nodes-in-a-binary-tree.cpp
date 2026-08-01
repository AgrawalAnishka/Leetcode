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
    int ans =0 ; 
    int solve(TreeNode* root){
     
        if(root==NULL) { 
            return INT_MIN;
        }

        int left = solve(root->left);
        int right =  solve(root->right);
        if(root->val >= left && root->val >= right){
            ans++;
        }

        return max({left , right , root->val });
        
    }
    int countDominantNodes(TreeNode* root) {
         solve(root);
        return ans ;
    }
};
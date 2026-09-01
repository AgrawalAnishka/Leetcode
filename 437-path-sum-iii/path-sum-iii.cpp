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
    int ctr  =0 ;

    void updateAns(TreeNode* root, long long targetSum){
        if(root==NULL) return ; 
        if(targetSum==root->val) ctr++;
        updateAns(root->left ,  targetSum - root->val);
        updateAns(root->right ,  targetSum - root->val) ; 
    }
    void solve(TreeNode* root, int targetSum){
        if(root==NULL){
            return ; 
        }
          

        updateAns(root  , targetSum); 


        solve(root->left ,  targetSum);
        solve(root->right , targetSum);

     
    }
    int pathSum(TreeNode* root, int targetSum) {
        solve(root , targetSum ) ;
        return ctr ;
    }
};
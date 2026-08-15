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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder ,  int l , int r , int idx){
        if(l>r || idx >= preorder.size()) return NULL;

        TreeNode * root= new TreeNode(preorder[idx]);
        for(int i =l ;i <= r ; i++){
            if(inorder[i]==preorder[idx]){

            root->left = solve(preorder ,  inorder, l , i-1, idx+1);
            root->right = solve(preorder, inorder , i+1  , r,idx + (i-l)+1);
            break;
            }
        }
        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder , inorder, 0 , preorder.size()-1 ,  0 ) ; 

    }
};
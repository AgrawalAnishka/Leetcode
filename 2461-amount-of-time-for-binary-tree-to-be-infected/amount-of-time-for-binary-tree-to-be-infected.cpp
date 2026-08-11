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
unordered_map<int ,  set<int>> mp;
// vector<vector<int>> adj(1e5+1 ) ; 
void solve(TreeNode* root){
    if(root==NULL) return ;

    if(root->left){
        mp[root->val].insert(root->left->val);
        solve(root->left);
        mp[root->left->val].insert(root->val);
    }
    if(root->right){
        mp[root->val].insert(root->right->val) ;
         solve(root->right);
         mp[root->right->val].insert(root->val);
    }

}
    int amountOfTime(TreeNode* root, int start) {
        solve(root);

        queue<pair<int, int>> q;
        q.push({start , 0 });

        int ans  =0 ;
        while(!q.empty()){
            auto [ root , dis ] = q.front();
            q.pop();
            
            ans=max(ans, dis);

            for(auto i  :mp[root]){
                mp[i].erase(root);
                q.push({i , dis+1});
            }
            mp[root].clear();
        }

        return ans;
        
    }
};
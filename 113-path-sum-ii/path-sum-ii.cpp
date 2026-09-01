/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> output;
    vector<vector<int>> ans;
    void solve(TreeNode* root, int targetSum) {
        if (root == NULL) {

            return;
        }
        if (root->left == NULL && root->right == NULL && targetSum == root->val) {
            output.push_back(root->val); 
            ans.push_back(output);
            output.pop_back();

            return;
        }

        output.push_back(root->val);
        solve(root->left, targetSum - root->val);
        solve(root->right, targetSum - root->val);
        output.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return {};
        solve(root, targetSum);
        // vector<vector<int>> res;
        // for (auto it : ans) {
        //     res.push_back(it);
        // }
        return ans;
    }
};
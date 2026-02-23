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
    // vector<vector<int>> BFS(TreeNode * root){
    //     vector<vector<int>>ans;
    //     if(!root) return ans;
    //     queue<TreeNode*>q;
    //     q.push(root);

    //     while(!q.empty()){
    //         int n = q.size();
    //         vector<int>level;

    //         for(int i=0; i<n; i++){
    //             TreeNode* node = q.front();
    //             q.pop();

    //             level.push_back(node->val);

    //             if(root->left) q.push(root->left);
    //             if(root->right) q.push(root->right);
    //         }

    //         ans.push_back(level);
    //     }
    //     return ans;
    // }
    vector<int> rightSideView(TreeNode* root) {
        // vector<vector<int>>levels = BFS(root);
        vector<int>ans;
        // for(auto &level: levels){
        //     right.push_back(level.back());
        // }
        recursive(root, 0, ans);
        return ans;
    }
    void recursive(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;
        if(level == ans.size()) ans.push_back(root->val);
        recursive(root->right, level+1, ans);
        recursive(root->left, level+1, ans);
    }
};
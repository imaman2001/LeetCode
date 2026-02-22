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
private: 
    void postOrder(TreeNode* root, vector<int>& res){
        if(!root) return;
        postOrder(root->left , res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }
public:
    // vector<int> num = {};
    vector<int> postorderTraversal(TreeNode* root) {
        // if(root == nullptr) return num;

        // postorderTraversal(root->left);
        // postorderTraversal(root->right);
        // num.push_back(root->val);
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};
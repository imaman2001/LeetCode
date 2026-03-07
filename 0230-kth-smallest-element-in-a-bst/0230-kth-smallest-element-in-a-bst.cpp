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
    // Brute force
    void inOrder(TreeNode* root, vector<int>& ans){
        if(root){
            inOrder(root->left, ans);
            ans.push_back(root->val);
            inOrder(root->right, ans);
        }   
    }
    int kthSmallest(TreeNode* root, int k){
        vector<int>ans;
        inOrder(root, ans);
        return ans[k-1];
    }

    // int kthSmallest(TreeNode* root, int k) {
    //     if(root == NULL) return -1;
        
    //     int left = kthSmallest(root->left , k);
    //     if(left != -1){
    //         return left;
    //     }
    //     k--;
        
    //     if(k == 0){
    //         return root->val;
    //     }
        
    //     int right = kthSmallest(root->right, k);
    //     return right;
    // }
};
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
    void inOrderTraversal(TreeNode* root, vector<int>&ans){
        if(!root) return;

        inOrderTraversal(root->left, ans);
        ans.push_back(root->val);
        inOrderTraversal(root->right, ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>inOrder;

        inOrderTraversal(root, inOrder);

        int left = 0;
        int right = inOrder.size()-1;

        while(left < right){
            int sum = inOrder[left] + inOrder[right];

            if(sum == k)return true;
            else if(sum < k) left++;
            else right--;
        }
        return false;
    }
};

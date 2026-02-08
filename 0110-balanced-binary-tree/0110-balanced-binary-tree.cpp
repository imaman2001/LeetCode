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
    int dfs(TreeNode* node){
        if(node == nullptr) return 0;

        int leftH = dfs(node->left);
        if(leftH == -1) return -1;

        int rightH = dfs(node->right);
        if(rightH == -1) return -1;

        if(abs(leftH - rightH) > 1) return -1;

        return 1 + max(leftH, rightH);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(dfs(root) == -1) return false;
        return true;
    }
};
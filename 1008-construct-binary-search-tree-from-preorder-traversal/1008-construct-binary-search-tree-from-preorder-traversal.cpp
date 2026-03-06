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
    TreeNode* build(vector<int>&A, int &i, int upperBound){
        if(i == A.size() || A[i]>upperBound) return NULL;

        TreeNode* root = new TreeNode(A[i]);
        i++;

        root->left = build(A, i, root->val);
        root->right = build(A, i, upperBound);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i=0;
        return build(A, i, INT_MAX);
    }
};
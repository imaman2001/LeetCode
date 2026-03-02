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

    TreeNode* func(vector<int>& preorder, int prest, int preend, vector<int>& inorder, int inst, int inend , map<int,int>& mp){
        // base case
        if(prest > preend || inst > inend) return NULL;

        TreeNode* root = new TreeNode(preorder[prest]);
        int inRoot = mp[root->val]; // idx
        int numLeft = inRoot - inst;

        root->left = func(preorder, prest+1, prest+numLeft , inorder, inst , inRoot-1, mp);
        root->right = func(preorder, prest + numLeft+1, preend, inorder, inRoot+1, inend, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // create a map for inOrder <val, idx>
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = func(preorder, 0 , preorder.size()-1, inorder , 0, inorder.size()-1 , mp);

        return root;
    }

};
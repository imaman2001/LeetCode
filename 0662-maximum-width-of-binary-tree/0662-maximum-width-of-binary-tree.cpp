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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=1;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0}); 

        while(!q.empty()){
            int size = q.size();
            int first = q.front().second;
            int last = q.back().second;
            ans = max(ans, last-first+1);

            for(int i=0; i<size; i++){
                auto curr = q.front();
                TreeNode* node = curr.first;
                int idx = curr.second - first;
                q.pop();
                
                if(node->left) q.push({node->left , 2LL*idx+1});
                if(node->right) q.push({node->right , 2LL*idx+2});
            }
        }
        return ans;
    }
};
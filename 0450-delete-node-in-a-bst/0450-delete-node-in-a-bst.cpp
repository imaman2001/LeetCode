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
    TreeNode* getInorderSuccessor(TreeNode* node){
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }
public:
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if(root == NULL) return NULL;

    //     if(key < root->val){
    //         root->left = deleteNode(root->left, key);
    //     } else if (key > root->val){
    //         root->right = deleteNode(root->right, key);
    //     } else {
    //         //root == key
    //         // case 1 : leaf Node
    //         if(root->left == NULL && root->right == NULL){
    //             delete root;
    //             return NULL;
    //         } 

    //         // case 2 : with 1 child
    //         if(root->left == NULL || root->right == NULL){
    //             return root->left == NULL ? root->right : root->left;
    //         }

    //         //case 3 : with 2 children
    //         TreeNode* IS = getInorderSuccessor(root->right);
    //         root->val = IS->val;
    //         root->right = deleteNode(root->right, IS->val);
    //         return root;
    //     }

    //     return root;
    // }

    TreeNode* deleteNode(TreeNode* root, int key){
        if(!root) return NULL;
        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }

        TreeNode* rightRoot = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightRoot;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;

        return findLastRight(root->right);
    }

};
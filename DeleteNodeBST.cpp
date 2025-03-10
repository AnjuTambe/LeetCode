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
 TreeNode* getInorderSuccessor(TreeNode *  root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
 }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return nullptr;
        }
        if(key < root->val){
          root->left =   deleteNode(root->left , key);
        }
        else if(key > root->val){
           root->right =  deleteNode(root->right , key);
        }
        else{
            // root == key
            // case 1 : with 0 children
            if(root->left == NULL && root->right == NULL){
                 delete root;
                 return NULL;
            }
                // case 2 : with 1 children
            if(root->left == NULL || root->right == NULL){
                    return root->left == NULL ? root->right : root->left;
            }

            // case 3  : with 2 children
                  TreeNode* IS = getInorderSuccessor(root->right);
                  root->val = IS->val;
                  root->right = deleteNode(root->right , IS->val);
                  return root;

            }
             return root;
        }
       
};
class Solution {
public:
//this is balanced tree so, Time Complexity will be O(log n)
// space complexity will be O(log n) because of recursion stack
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        if(root->val == val){
            return root;
        }
        else if(root->val > val){
          return searchBST(root->left , val);
        }
        else{
            return searchBST(root->right , val);
                
            }
        }
    };
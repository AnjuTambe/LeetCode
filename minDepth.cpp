class Solution {
public:
    int minDepth(TreeNode* root) {
        //base condition 
        if(root == NULL){
            return 0;
        }
        //calculate the depth of left and right subtree
        int leftHt = minDepth(root->left);
        int rightHt = minDepth(root->right);
        
        //if one of the subtree is null. we take depth of the other subtree
        if(root->left == NULL){
            return rightHt +1;
        }
        if(root->right == NULL){
            return leftHt + 1;
        }
        //if both subtree is exists then 
        return min(leftHt, rightHt) +1;
    }
};
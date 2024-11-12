class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftHt = maxDepth(root->left);
        int rightHt = maxDepth(root->right);

        int currHt = max(leftHt , rightHt) +1;
        return currHt;

    }
};
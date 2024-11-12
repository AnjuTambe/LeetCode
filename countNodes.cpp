class Solution {
public:
    int countNodes(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    int finalCount = leftCount + rightCount + 1;
    return finalCount;
    }
};
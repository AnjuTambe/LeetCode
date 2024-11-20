class Solution {
public:

    bool isIdentical(TreeNode* root1, TreeNode*root2){
        //base case
         if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }
     return  isIdentical(root1->left , root2->left) 
             && isIdentical(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //base case
        if(root == NULL && subRoot == NULL){
            return true;
        }
        else if(root == NULL || subRoot == NULL){
            return false;
        }

    if(root->val == subRoot->val){
        // check for identical structure and nodes values
       if(isIdentical(root , subRoot)){
            return true;
        }
    }
   int IsleftSubtree = isSubtree(root->left , subRoot);
    if(!IsleftSubtree){
      return isSubtree(root->right, subRoot);
    }
    return true;
}
};
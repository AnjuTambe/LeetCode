/ TC : O(n) but in worst case O(n^2)
 //Space complexity O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
     
     // base case 
        if(root == NULL){
            return {};
        }

        vector<int>left = inorderTraversal(root->left);
        result.insert(result.end() , left.begin() , left.end()); // insert is performing O(n)

        result.push_back(root->val);   // O(1)

        vector<int>right = inorderTraversal(root->right);
        result.insert(result.end() , right.begin() , right.end());    // O(n)

        return result;
    }
};
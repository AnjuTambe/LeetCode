class Solution:
    def lowestCommonAncestor(self , root , p ,q) :

        #Base case 
        if not root or root == p or root == q:
            return root

        # recursion DFS
        left = self.lowestCommonAncestor(root.left , p ,q)
        right = self.lowestCommonAncestor(root.right , p , q)

        # if we got the both p and q value then their root is the LCA

        if left and right : 
            return root

        # if we got the p or q value in subtree and the other value is null then 
        # which value is got that itself is the LCA
        # Return whichever side is not None (the side where we found p or q)


        if left: 
            return left

        else: 
            return right    

# Time complexity : O(n)
# space complexity : O(h) height of the tree
#include <iostream>
#include "vector"
using namespace std;
class Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = right = nullptr;  // at first, it's null
    }
};

static int idx = -1;
Node * buildTree(vector<int> nodes){
    idx++;
    //Base condition
    if(nodes[idx] == -1){
        return  NULL;
    }
    Node * currNode = new Node(nodes[idx]);
    currNode->left  = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

int heightOfBT(Node *root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);

    int currHeight = max(leftHeight, rightHeight) + 1;
    return currHeight;
}

int diam1(Node*root){   //O(n^2)
    if(root == NULL){
        return 0;
    }
    //you are assuming that big diameter goes through root node
    int currDiam = heightOfBT(root->left) + heightOfBT(root->right) + 1;  // this line is taking time O(n)
    // when the diameter longest path in the left subtree or right-subtree
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);
    return max( max(leftDiam, rightDiam), currDiam);
}


//optimal approach by making pair<int, int> TC: O(n)
pair<int, int> diam2(Node*root){
    if(root == NULL){
        return make_pair( 0, 0);
    }
    pair<int, int> leftInfo = diam2(root->left); // LeftDiam , LeftHeight
    pair<int, int> rightInfo = diam2(root->right); // rightDiam , rightHeight

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam , max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;
    return make_pair(finalDiam, finalHt);
}
int main() {
   vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(nodes);
   cout << diam2(root).first << endl;
   cout<<diam2(root).second<<endl;

    return 0;
}

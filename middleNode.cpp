class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* curr = head;
       int count = 0;
       while(curr != nullptr){
          count++;
          curr = curr->next;
       }
    
       int middleIndex = count/2;
       //traverse through middleIndex
         curr = head;
       for(int i=0; i<middleIndex; i++){
            curr = curr->next;
       }
       return curr;   // middle node
    }
};
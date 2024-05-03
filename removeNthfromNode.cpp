class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while(curr != nullptr){
           count++;
           curr = curr->next;
        }

        int nodeIndexToDelete = count - n; // 5 - 2 = 3
        
        // Head delete
        if(nodeIndexToDelete == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
    
        curr = head;
        for(int i=0; i < nodeIndexToDelete-1; i++){//0,1
            curr = curr->next; 
        }  
        
        ListNode* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete nodeToDelete;
        return head;
    }
};
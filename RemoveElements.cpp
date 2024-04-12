class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode *prev = nullptr;

        while(curr != nullptr){
            if(curr-> val == val){
                if(prev == nullptr){
                    head = curr->next;
                    delete curr;
                    curr = head;
                }
                else{
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
       
     }  
};
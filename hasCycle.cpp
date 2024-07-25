class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next; //+1
            fast = fast->next->next;  //+2

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
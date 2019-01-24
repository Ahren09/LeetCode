class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0;
        ListNode* first=head;
        while(i<n)
        {
            first=first->next;
            i++;
        }
        ListNode* second=head;
        if(!first) //Target node is head node
        {
            head=head->next; 
            delete second;
            
        }
        else{
            while(first->next)
            {
                first=first->next;
                second=second->next;
            }
            ListNode* p=second->next;
            second->next=second->next->next;
            delete p;
        }
        return head;
        
    }
};

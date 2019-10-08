class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1||!l2)
            return nullptr;
        ListNode *node, *head=new ListNode(-1);
        node=head;
        bool carry=false;
        int sum, remainder;
        while(l1 && l2)
        {
            sum=l1->val + l2->val+carry;
            remainder=sum%10;
            node->next=new ListNode(remainder);
            carry= (sum!=remainder);
            
            node=node->next;
            l1=l1->next;
            l2=l2->next;
            if(!l1&&!l2)
                break;
            if(!l1)
                l1=new ListNode(0);
            if(!l2)
                l2=new ListNode(0);
        }
        if(carry)
            node->next=new ListNode(carry);
        return head->next;
    }
};

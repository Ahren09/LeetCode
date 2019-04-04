class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node* newHead = new Node(head->val, nullptr, nullptr);
        Node* p=head->next;
        Node* n=newHead;
        unordered_map<Node*, Node*> m;
        m[head]=newHead; //DO NOT forget to include the head node
        
        //Standard practice of copying singly-linked list
        while(p)
        {
            Node* tmp=new Node(p->val, nullptr, nullptr);
            n->next=tmp;
            m[p]=tmp;
            p=p->next;
            n=n->next;
        }
        
        p=head;
        n=newHead;
        while(n)
        {
            n->random=m[p->random];
            p=p->next;
            n=n->next;
        }
        
        return newHead;
    }
};
/Users/jinyiqiao/Desktop/Git/LeetCode_CPP/LeetCode/LeetCode

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    :head(nullptr),tail(nullptr),m_size(0)
    {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0 || index>=m_size)
            return -1;
        Node* p=head;
        for(; index>0;p=p->next,index--);
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(m_size,val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<0 || index>m_size)
            return;
        
        Node* p=head;
        Node* q=nullptr;
        int count=0;
        while(count<index)
        {
            q=p;
            p=p->next;
            count++;
        }
        Node* newNode=new Node;
        newNode->val=val;
        newNode->next=p;
        newNode->pre=q;
        
        if(p)
            p->pre=newNode;
        else tail=newNode;
        if(q)
            q->next=newNode;
        else head=newNode;
        
        m_size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0 || index>=m_size)
            return;
        Node* p = head;
        while(index>0)
        {
            p=p->next;
            index--;
        }
        if(p!=head)
            p->pre->next=p->next;
        else head=head->next;
        if(p!=tail)
            p->next->pre=p->pre;
        else tail=tail->pre;
        
        delete p;
        m_size--;
        
    }
    private:
    struct Node{
        int val;
        Node* pre;
        Node* next;
    };
    Node* head;
    Node* tail;
    int m_size;
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

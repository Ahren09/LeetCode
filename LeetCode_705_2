class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {}
    
    void add(int key) {
        if(set[key]==0)
            set[key]++;
    }
    
    void remove(int key) {
        if(set[key]>0)
            set[key]--;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(set[key]>0)
            return true;
        return false;
    }
private:
    int set[1000001]={0};
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {}
    
    void add(int key) {
        if(!contains(key))
            HashTable[hashcode(key)].push_back(key);
    }
    
    void remove(int key) {
        int arraynum=hashcode(key);
        auto const iter = find(HashTable[arraynum].begin(),HashTable[arraynum].end(),key);
        if(iter!=HashTable[arraynum].end())
        HashTable[arraynum].erase(iter);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int arraynum=hashcode(key);
        auto const iter = find(HashTable[arraynum].begin(),HashTable[arraynum].end(),key);
        return iter!=HashTable[arraynum].end();
    }
private:
    array<list<int>,100> HashTable;
    int hashcode(int key){
        return key%100;
    }
};

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left;i<=right; i++)
        {
            if(isSelfDividing(i))
                v.push_back(i);
        }
        return v;
    }
    bool isSelfDividing(int num)
    {
        set<int> s;
        int n=num;
        while(n%10)
        {
            s.insert(n%10);
            n/=10;
        }
        if(n!=0) return false;
        for(int i:s)
        {
            if(i==0 || num%i!=0)
                return false;
        }
        return true;
    }
};

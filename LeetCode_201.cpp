class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i=0;
        while(m!=n)
        {
            m>>=1;
            n>>=1;
            i++;
        }
        return (m<<i);
    }
};

//We only need to keep the common bits of all integers in the range

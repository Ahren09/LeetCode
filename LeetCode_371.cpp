
//First submission: misterious "left shift of negative value"
class Solution {
public:
    int getSum(int a, int b) {
        return b==0?a:getSum(a^b, (a&b)<<1);
    }
};

#include <stdio.h>

public:
vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int SumA=0,SumB=0;//这里sum必须初始化为0，C++对int没有自动初始化
    int num=0;
    while(num<A.size())
        SumA+=A[num++];
    num=0;
    while(num<B.size())
        SumB+=B[num++];
    vector<int> result(2,0);
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
            if(2*(A[i]-B[j])==SumA-SumB){
                result[0]=A[i];
                result[1]=B[j];
                return result;
            }
    
}

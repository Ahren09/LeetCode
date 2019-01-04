public:
vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int SumA=0,SumB=0,num=0;
        for(int i:A)
            SumA+=i;
        for(int i:B)
            SumB+=i;
        for(int i=0;i<A.size();i++)
            for(int j=0;j<B.size();j++)
                if(2*(A[i]-B[j])==SumA-SumB){
                    return {A[i],B[j]};
                }       
    }

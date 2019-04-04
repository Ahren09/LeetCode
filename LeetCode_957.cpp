#include <vector>
#include <iostream>
using namespace std;

//First submission: Time Limit Exceeded
//class Solution {
//public:
//    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
//        for(int i=0;i<N;i++)
//        {
//            vector<int> v(8,0);
//            for(int i=1;i<7;i++)
//            {
//                v[i]=cells[i-1]==cells[i+1] ? 1 : 0;
//            }
//            cells=v;
//        }
//        return cells;
//    }
//};

void printVec(vector<int> v)
{
    for(int j=0;j<8;j++)
        cout<<v[j]<<", ";
    cout<<endl;
}

//Second submission
//NOTICE that cycles for each pattern is different
vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<vector<int>> pattern;
    int start=0, cycle=0;
    
    vector<int> zero=cells;
    pattern.push_back(zero);
    bool flag=false;
    for(int i=1;i<=N;i++)
    {
        if(flag) break;
        vector<int> v(8,0);
        for(int j=1;j<7;j++)
        {
            v[j]=pattern[i-1][j-1]==pattern[i-1][j+1] ? 1 : 0;
        }
        if(i==N) return v;
        int j;
        for(j=0;j<pattern.size();j++)
        {
            if(v==pattern[j])
            {
                start=j;
                cycle=i-start;
                flag=true;
                break;
            }
        }
        if(j==pattern.size()) pattern.push_back(v);
    }
    N=(N-start)%cycle+start;
    return pattern[N];
    
}


int main()
{
    vector<int> v={0,0,1,1,1,1,0,0};
    printVec(prisonAfterNDays(v, 8));
        
}



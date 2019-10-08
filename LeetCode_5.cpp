
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    int maxLen = 0, maxEnd = 0;
    int LEN = s.size();
    int m[LEN];
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    
    for(int i=0; i<LEN; i++){
        m[i] = (rev_s[i] == s[0] ? 1 : 0);
    }
    
    for(int i=0; i<LEN; i++){
        for(int j=LEN-1; j>=0; j--){
            if(s[i] == rev_s[j]){
                if(i==0 || j==0){
                    m[j] = 1;
                }
                else{
                    m[j] = m[j-1]+1;
                }
                if(m[j] > maxLen){
                    int beforeRev = LEN - j - 1;
                    if(beforeRev + m[j] - 1 == i){
                        maxLen = m[j];
                        maxEnd = i;
                    }
                }
                
            }
            else
                m[j] = 0;
        }
    }
    return s.substr(maxEnd-maxLen+1, maxEnd+1);
}

int main(){
    string s = "cbbd";
    string res = longestPalindrome(s);
    cout<<res;
}

//Recursive solution

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;

void dfs(int i, string digits, string path, vector<string>& res);

vector<string> dict={"", "","abc","def","ghi","jkl","mno","pqrs", "tuv","wxyz"};
vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.size() > 0)
        dfs(0, digits, "", res);
    return res;
}
void dfs(int i, string digits, string path, vector<string>& res){
    //Process last digit
    int index = digits[i]-48;
    
    if(i == digits.size()-1){
        for(char c:dict[index]){
            res.push_back(path+c);
        }
        return;
    }
    for(char c: dict[index]){
        dfs(i+1, digits, path+c, res);
    }
}

int main(){
    string input = "23";
    vector<string> res = letterCombinations(input);
    for(string s:res){
        cout<<s<<endl;
    }
}

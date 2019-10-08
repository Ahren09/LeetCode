//Recursive solution

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void populateTwoSum(vector<int>& nums, int i, vector<vector<int>>& res);

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() < 3)
        return res;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>0)
            break;
        if(i>0 && nums[i] == nums[i-1])
            continue;
        populateTwoSum(nums, i, res);
    }
    return res;
    
    
    
}
    
void populateTwoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
    int target= -nums[i];
    int left = i+1, right = nums.size()-1;
    while(left<right){
        int twoSum = nums[left]+nums[right];
        if(twoSum < target)
            left++;
        else if (twoSum > target)
            right--;
        else{
            vector<int> v{-target, nums[left], nums[right]};
            
            res.push_back(v);
            
            //Eliminate results with same numbers
            while(left<right && nums[left]==nums[left+1])
                left++;
            while(left<right && nums[right]==nums[right-1])
                right--;
            left++;right--;
        }
    }
}

int main(){
    s = "babad";
    
}

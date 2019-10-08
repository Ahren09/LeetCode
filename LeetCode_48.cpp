class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& nums, int index){
        int SIZE = nums.size();
        if (index==SIZE-1){
            vector<int> tmp;
            res.push_back(nums);
        }
        for(int i=index; i<SIZE; i++){
            swap(nums[index],nums[i]);
            dfs(res, nums, index+1);
            swap(nums[index],nums[i]);
        }
    }
};

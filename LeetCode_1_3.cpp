class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> v;
        int SIZE=nums.size();
        for(int i=0;i<SIZE;i++)
        {
            int other=target-nums[i];
            if(m.find(other)!=m.end())
            {
                //If index are different
                //e.g: (3,3)
                if(m[other]!=i)
                {
                    v.push_back(m[other]);
                    v.push_back(i);
                    break;
                }
            }
            //Insert the new element at the end
            //to prevent confusion with the other element
            m[nums[i]]=i;
        }
        return v;
    }
};

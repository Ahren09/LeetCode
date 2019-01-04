  vector<int> twoSum(vector<int>& nums, int target) 
  {
        vector<int>::iterator p,q;
        vector<int> result(2);
        for(p=nums.begin(); p!=nums.end(); p++)
        {
            for(q=p; q!=nums.end(); q++)
            {
                if(*q=target-*p)
                {
                 result.push_back(p);
                 result.push_back(q);
                }
                return result;
            }
        }
}

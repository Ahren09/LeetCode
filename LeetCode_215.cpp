class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int SIZE=nums.size();
        if(nums.size()==1)
            return nums[0];
        int start=nums.size()-1;
        int i;
        for(i=SIZE;i>=SIZE-k;i--)
            shift_down(nums,start,SIZE);
        return nums[SIZE-i];
        
        
    }
    
    //i is root of subtree
    //n is size of heap
    void shift_down(vector<int>& v, int i, int n)
    {
        int largest=i;
        int l,r;
        
        while(largest<i)
        {
            largest=i;
            l=i*2+1;
            r=i*2+2;
            if(l<n && v[l]>v[largest])
                largest=l;
            if(r<n && v[r]>v[largest])
                largest=r;
            if(largest!=i)
            {
                swap(v[largest],v[i]);
                i=largest;
            }
            else break;
        }
    }
    
    void shift_up(vector<int>& a, int index)
    {
        int p=index;
        while(p>0)
        {
            int parent=(p-1)/2;
            if(a[parent]<a[p])
                swap(a[parent],a[p]);
            p=parent;
            
        }
    }
};

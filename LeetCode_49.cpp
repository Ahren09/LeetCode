class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>result;
        map<string,vector<string> > mp;
        for(string s: strs)
        {
            string cp=s;
            sort(cp.begin(),cp.end());
            mp[cp].push_back(s);
        }
        for(map<string,vector<string> >::iterator it=mp.begin();it!=mp.end();it++)
        {
            result.push_back(it->second);
        }
        
        return result;
    }
};

int lengthOfLongestSubstring(string s) {
    int start = 0, maxLen = 0, len = s.size();
    unordered_map<char, int> mp;
    for(int index=0; index<len; index++){
        char c = s[index];
        // Found duplicate char
        if(mp.find(c) != mp.end() && start<=mp[c])
            start=mp[c]+1;
        else{
            maxLen = max(maxLen, index-start+1);
        }
        mp[c] = index;
    }
    return maxLen;
}
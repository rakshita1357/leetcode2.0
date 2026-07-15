class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ans;
        if(s.length()<1) return 0;
        int l=0,res=INT_MIN;
        for(int r=0;r<s.length();r++){
            while(ans.count(s[r])){
                ans.erase(s[l]);
                l++;
            }
            ans.insert(s[r]);
            res=max(res,r-l+1);
        }
        return res;
    }
};
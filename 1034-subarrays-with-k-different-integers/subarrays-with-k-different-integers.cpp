class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>&nums,int k){
        int l=0,res=0;
        unordered_map<int,int> ma;
        for(int i=0;i<nums.size();++i){
            if(!ma[nums[i]]++)
                k--;
            while(k<0){
                if(!--ma[nums[l]]) k++;
                l++;
            }
            res+=i-l+1;
        }
        return res;
    }
};
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxi=nums[0],mini=nums[nums.size()-1];
        int l=-1,r=-1;
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            if(nums[i]<maxi){
                r=i;
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            mini=min(mini,nums[i]);
            if(nums[i]>mini){
                l=i;
            }
        }
        if(r==-1||l==-1) return 0;
        return r-l+1;
    }
};
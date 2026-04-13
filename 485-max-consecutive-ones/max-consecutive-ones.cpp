class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,l=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                l=i+1;
            }
            else 
                maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};
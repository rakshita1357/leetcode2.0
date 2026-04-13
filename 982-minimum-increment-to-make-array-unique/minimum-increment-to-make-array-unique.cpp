class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,new_n=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<=nums[i-1]){
                new_n=nums[i-1]+1;
                count+=new_n-nums[i];
                nums[i]=new_n;
            }
        }
        return count;
    }
};
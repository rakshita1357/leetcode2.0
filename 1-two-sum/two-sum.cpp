class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>ans;
        int num=0;
        for(int i=0;i<nums.size();++i){
            num=nums[i];
            if(ans.find(target-num)!=ans.end()){
                return{i,ans[target-num]};
            }
            ans[num]=i;
        }
        return{};
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sum=0;
        vector<int> res;
        int left=0,right=numbers.size()-1;
        while(left<right){
            sum=numbers[left]+numbers[right];
            if(sum==target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
        }
        return res;
    }
};
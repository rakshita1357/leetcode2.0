class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end()),r=0;
        int d=0,sum=0;
        for(auto i:weights){
            r+=i;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            d=0;
            sum=0;
            for(auto i: weights){
                sum+=i;
                if(sum>mid){
                    d++;
                    sum=i;
                }
            }
            if(sum<=mid) d++;
            if(d<=days) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
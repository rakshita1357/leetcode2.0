class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid=0,ans=INT_MAX;
        long long sd;
        int l=1,r=0;
        for(auto i: piles){
            r=max(r,i);
        }
        
        while(l<=r){
            mid=l+(r-l)/2;
            sd=0;
            for(auto i:piles){
                    sd += i/mid;
                    if((i%mid)>0) sd++;
            }
            if(sd<=h){
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
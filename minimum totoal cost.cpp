class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        double dd=k;
        double r_l=k;
        long long res=0;
        const long long MOD=1000000007;
        
        for(int i=0;i<nums.size();i++)
        {
             if(r_l<nums[i])
             {
                double diff=nums[i]-r_l;
                double ans=ceil(diff/dd);
                res+=ans;
                r_l=ans*k+r_l-nums[i];
             }
             else
             {
                   r_l-=nums[i];
             }
        }
        __int128 temp=(__int128)res*(res+1);
        temp/=2;
        return (long long)(temp%MOD);
    }
};

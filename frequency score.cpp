class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        int ans=0;
        while(n)
        {
            int digit=n%10;
            mp[digit]++;
            n=n/10;
        }
        for(auto &it: mp)
        {
            ans+=it.first*it.second;
        }
        return ans;
    }
};

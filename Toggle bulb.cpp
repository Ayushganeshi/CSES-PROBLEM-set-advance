class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int n=bulbs.size();
        for(int i=0;i<n;i++)
        {
            mp[bulbs[i]]++;
        }
        for(auto &val :mp)
        {
            if(val.second%2==1)
            ans.push_back(val.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

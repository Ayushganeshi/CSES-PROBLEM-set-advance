class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto &val :nums)
        {
            freq[val]++;
        }
        
        unordered_map<int,int>frcount;
        for(auto &it :freq)
        {
           frcount[it.second]++;
        }
        unordered_set<int>st;
        for(auto &val :nums)
        {
            if(st.count(val))
            continue;
            st.insert(val);

            int f=freq[val];
            if(frcount[f]==1)
            return val;
        }
        return -1;

    }
};

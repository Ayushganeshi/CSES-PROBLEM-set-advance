class Solution {
public:
    int secondHighest(string s) {
        int n=s.size();
        set<int>st;
        for(int i=0;i<n;i++)
        {
            if(islower(s[i]))continue;
            else
            st.insert((s[i]-'0'));
        }
        vector<int>ans(st.begin(),st.end());
        if(ans.size()==0 || ans.size()<2)
        return -1;
        

        return ans[ans.size()-2];
    }
};

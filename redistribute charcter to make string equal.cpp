class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>mp;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
           string s=words[i];
           int m=s.size();
           for(int i=0;i<m;i++)
           {
               mp[s[i]]++;
           }
        }
        for(auto &it : mp)
        {
            if(it.second %n!=0)
            {
               return false;
            }
        }
        return true;
    }
};

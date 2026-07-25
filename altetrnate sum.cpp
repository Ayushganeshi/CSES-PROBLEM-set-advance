class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int ans=0;
        int p=s.size();
        for(int i=0;i<p;i++)
        {
            if(i%2==0)
            {
                ans+=(s[i]-'0');
            }
            else
            {
                ans-=(s[i]-'0');
            }
        }
        return ans;
    }
};

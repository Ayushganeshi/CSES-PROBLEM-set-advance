class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string temp=s;
        bool _flagy=false;
        bool _flagx=false;
        string ans="";
        if(temp.find(y)!=string::npos)
        {
            _flagy=true;
        }
        if(temp.find(x)!=string::npos)
        {
            _flagx=true;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==y)
            ans+=s[i];
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=y)
            ans+=s[i];
        }
        return ans;
    }
};

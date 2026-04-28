class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>v;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                v.push_back(grid[i][j]);
            }
        }
        int l=v.size();
        sort(v.begin(),v.end());/// le beta om foooo
        int tr=v[l/2];
        int res=0;
        for(auto & val : v)
        {
            if(val%x!=tr%x)//achaaaaa
            {
                return -1;
            }
            res+=abs(tr-val)/x;/// well done ayush
        }
        return res;
    }
};

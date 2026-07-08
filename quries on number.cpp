class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int h=queries[i][0];
            int k=queries[i][1];
            int r=queries[i][2];
            int count=0;
            for(int j=0;j<points.size();j++)
            {
                int x=points[j][0];
                int y=points[j][1];
                 if((x-h)*(x-h)+(y-k)*(y-k)<=r*r)
                 {
                    count++;
                 }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(words[i]==target)
            {
                int dist=abs(startIndex-i);
                int cir_dist=abs(n-dist);
                ans=min({ans,dist,cir_dist});
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;

    }
};

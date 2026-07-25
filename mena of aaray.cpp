class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int r=n/20;
        double sum=0;
        for(int i=r;i<n-r;i++)
        {
           sum+=arr[i];
        }
        double avg=sum/(n-(2*r));
        return avg;
    }
};

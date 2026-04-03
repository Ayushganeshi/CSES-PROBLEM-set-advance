class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        if(nums.size()==k)
        return nums;                  ////////////////space complexity(0(n))
            /////////////////////////////////in heap push and top takes logk time where k is the number of elemnt in the heap
))
        for(int  i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;

        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(k--)
        {
            auto[freq,value]=pq.top();
            ans.push_back(value);
            pq.pop();


        }
        return ans;
    }
};

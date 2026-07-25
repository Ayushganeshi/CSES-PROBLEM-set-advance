class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int pos = INT_MAX;
        int neg = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg = max(neg,nums[i]);
            }
            else{
                pos = min(pos,nums[i]);
            }
        }
        if(neg==INT_MIN) return pos;
        if(pos==INT_MAX) return neg;

        if(abs(neg)<pos){return neg;}
        else if(abs(neg)>pos){return pos;}
        return pos;
    }
};

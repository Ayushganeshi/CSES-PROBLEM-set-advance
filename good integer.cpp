class Solution {
public:
    bool checkGoodInteger(int n) {
        int d_sum=0;
        int sq_sum=0;
        while(n)
        {
            int digit=n%10;
            d_sum+=digit;
            sq_sum+=(digit*digit);
            n=n/10;
        }
        return sq_sum - d_sum >= 50;
    }
};

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double degree_min=5.5*minutes;//
        double degree_hour=30*hour;//90
        double res=abs(degree_min-degree_hour);
        if(res>180)
        return 360-res;
        else 
        return res;
        
    }
};

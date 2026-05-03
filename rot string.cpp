class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string doubled = s + s;///////////////// log n

        return doubled.find(goal) != string::npos;////////////// o(n)
    }
};

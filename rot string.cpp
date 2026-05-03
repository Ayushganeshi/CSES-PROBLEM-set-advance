class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string doubled = s + s;/////////  //// time coplexity 0(n)

        return doubled.find(goal) != string::npos;////////////// space complexity   0(1)
    }
};

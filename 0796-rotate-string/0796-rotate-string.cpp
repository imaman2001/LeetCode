class Solution {
public:
    bool rotateString(string s, string goal) {
        // s= s+s;
        // return s.find(goal) != -1 and s.size() / 2 == goal.size();
        if(s.size() != goal.size()) return false;
        if(s == goal) return true;

        for(int i=0; i<s.size(); i++){
            string rotated = s.substr(i, s.size()-1) + s.substr(0, i);

            if(rotated == goal) return true;
        }
        return false;
    }
};
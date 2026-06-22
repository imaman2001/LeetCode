class Solution {
public:
    int countSegments(string s) {
        if(s.size() == 0) return 0;
        int ans = 0;

        for(int i=1; i<s.size(); i++){
            if(s[i] == ' ' && s[i-1] != ' '){
                ans++;
            }
        }
        if(s.back() != ' '){
            ans++;
        }
        return ans;
    }
};
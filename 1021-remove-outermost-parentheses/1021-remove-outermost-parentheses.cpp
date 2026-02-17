class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int level = 0;

        for(char ch : s){
            if(ch == '('){
                if(level > 0){
                    ans += ch;
                }
                level++;
            }else if(ch == ')'){
                level--;
                if(level > 0){
                    ans += ch;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> dummy;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                dummy.push(ch);
            } else {
                if(!dummy.empty()){
                    char curr = dummy.top();

                    if((ch == '}' && curr == '{') ||
                       (ch == ')' && curr == '(') ||
                       (ch == ']' && curr == '[')) {
                        dummy.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        if(dummy.empty()){
            return true;
        } else {
            return false;
        }
    }
};
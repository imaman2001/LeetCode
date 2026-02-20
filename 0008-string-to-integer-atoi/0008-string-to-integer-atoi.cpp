class Solution {
    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;
public:
    int myAtoi(string s) {
        int i=0; 
        int sign = 1;
        while(i<s.size() && s[i] == ' '){
            i++;
        }
        if(i<s.size() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-' ? -1 : 1);
            i++;
        }
        return helper(s,i,0,sign);
    }

    int helper(string &s, int i, long long num, int &sign){
        if(s.size()<=i || !isdigit(s[i])){
            return (int)(sign * num);
        }
        num = num * 10 + (s[i] - '0');

        if(sign * num <= INT_MIN_VAL) return INT_MIN_VAL;
        if(sign * num >= INT_MAX_VAL) return INT_MAX_VAL;

        return helper(s, i+1, num, sign);
    }
};
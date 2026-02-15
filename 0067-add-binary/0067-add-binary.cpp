class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string ans = "";
        int sum = 0;

        while(i>=0 || j>=0){
            sum = carry;
            if(i>=0){
                sum += a[i] - '0';
                i--;
            }
            if(j>=0){
                sum += b[j] - '0';
                j--;
            }

            ans.push_back((sum & 1) ? '1' : '0');
            carry = (sum > 1) ? 1 : 0;
        }
        if(carry != 0) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
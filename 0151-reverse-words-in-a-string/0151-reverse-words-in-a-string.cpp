class Solution {
public:
    string reverseWords(string s) {
        //BF :--> O(2N + nlogn)
        string ans = "";
        int n = s.size();
        int i = n-1;

        while(i>=0){
            while(i >= 0 && s[i] == ' '){
                i--;
            }

            if(i<0) break;
            int end = i;

            while(i>=0 && s[i] != ' '){
                i--;
            }
            string word = s.substr(i+1 , end-i);

            if(!ans.empty()){
                ans += " ";
            }

            ans += word;
        }
        return ans;
    }
};
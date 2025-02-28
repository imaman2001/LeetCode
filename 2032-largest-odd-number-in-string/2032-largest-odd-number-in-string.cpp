class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for(int i=n-1; i>=0; i--){
            if(int(num[i]) % 2 == 1){ // 2,
               return num.substr(0 , i+1); //make the substr and return 
            }
        }
        return "";
    }
};
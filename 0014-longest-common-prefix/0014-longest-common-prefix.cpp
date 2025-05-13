class Solution {
   
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.empty()) return "";

        string pre = str[0];
        for(string s : str){
            while(s.find(pre) != 0){      // match all the same and find the common prefix
                pre = pre.substr(0, pre.length()-1);
            }
        }
        return pre;
    }
};
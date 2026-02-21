class Solution {
public:
    int strStr(string str, string ptrn) {
        int idx = 0;
        if(str.length() < ptrn.length()){
            return -1;
        }
        for(int i=0; i<str.size(); ++i){
            if(str[i] == ptrn[idx]){
                idx++;
            }else {
                i = i-idx;
                idx = 0;
            }

            if(idx == ptrn.length()){
                return i-ptrn.length()+1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    char kthCharacter(long long k, vector<int>& opr) {
        long long length = 1;
        int totalOpr = 0;

        while(length < k){
            length *= 2;
            totalOpr++;
        }

        k--;

        int next = 0;
        for(int i=totalOpr-1; i>=0; i--){
            if(k >= length/2){
                if(opr[i] == 1){
                    next++;
                }
                k -= length/2;
            }
            length /= 2;
        }
        return (next % 26 + 'a');

        // string word = "a";
        // for(int i=0; i<opr.size(); i++){
        //     string next;
        //     for(char ch : word){
        //         if(opr[i] == 0){
        //             next = word;
        //         } else {
        //             if(ch == 'z'){
        //                 next += 'a';
        //             } else {
        //                 next += ch + 1;
        //             }
        //         }
        //         word += next;
        //     }
        // }
        // return word[k-1];
    }
};
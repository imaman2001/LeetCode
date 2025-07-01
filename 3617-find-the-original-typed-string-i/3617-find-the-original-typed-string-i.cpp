class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;

        for(int i=1; i<word.length(); i++){
            char ch = word[i-1];
            if(ch == word[i]){
                count++;
            }
        }
        return count;
    }
};
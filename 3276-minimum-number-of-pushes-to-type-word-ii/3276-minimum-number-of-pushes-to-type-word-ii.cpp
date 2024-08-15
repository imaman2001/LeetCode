class Solution {
public:
    int minimumPushes(string word) {
        vector<int>letterFreq(26,0);
        for(char ch : word){
            letterFreq[ch -'a']++;
        }
        sort(letterFreq.rbegin() , letterFreq.rend());

        int totalPress = 0;
        for(int i=0; i<26; i++){
            if(letterFreq[i] == 0) break;
            totalPress = totalPress + (i/8+1) * letterFreq[i];
        }
        return totalPress;
    }
};
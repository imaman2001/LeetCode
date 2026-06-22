class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = 0;
        while(true){
            string wrd = "balloon";

            for(char &ch : wrd){
                bool match = false;

                for(char &c : text){
                    if(c == ch){
                        c = '#';
                        match = true;
                        break;
                    }
                }
                if(!match){
                    return ans;
                }
            }
            ans++;
        }
        return ans;
    }
};
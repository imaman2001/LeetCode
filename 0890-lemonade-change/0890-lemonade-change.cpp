class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveD=0, tenD=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                fiveD++;
            } else if(bills[i] == 10){
                if(fiveD > 0){
                    fiveD--;
                    tenD++;
                } else {
                    return false;
                }
            } else{
                if(fiveD > 0 && tenD > 0){
                    fiveD--;
                    tenD--;
                } else if(fiveD > 2){
                    fiveD = fiveD - 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
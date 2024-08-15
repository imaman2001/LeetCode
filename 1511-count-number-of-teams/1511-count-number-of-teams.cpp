class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total = 0;
        for(int i=0; i<rating.size(); i++){
            int rightL=0 , rightM=0 , leftL=0, leftM=0;

            for(int j=i+1; j<rating.size(); j++){
                if(rating[j] < rating[i]) rightL++;
                else if(rating[i] < rating[j]) rightM++;
            }
            for(int j=0; j<i; j++){
                if(rating[j] < rating[i]) leftL++;
                else if(rating[i] < rating[j]) leftM++;
            }
            total = total + rightL * leftM + rightM * leftL;
        }
        return total;
    }
};
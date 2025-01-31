class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;

        while(tickets[k] != 0){
            for(int i=0; i<tickets.size(); i++){
                if(tickets[i] > 0){
                    tickets[i]--; //[1,3,2] , [1,2,2], [1,2,1] , [0,2,1], [0,1,1], [0,1,0]
                    count++;     //1 ,2, 3, 4 , 5 , 6
                }
                if(tickets[k] == 0) break;
            }
        }
        return count;
    }
};
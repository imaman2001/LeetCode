class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();

            int ele = one - two;
            if(ele){
                pq.push(ele);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};
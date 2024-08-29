class Solution {
public:

    void dfs(int &n , int idx , vector<bool>& visited , vector<vector<int>>& stones){
        visited[idx] = true;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(stones[idx][0] == stones[i][0]){ // check all rows 0th index
                    dfs(n , i , visited , stones);
                }
                if(stones[idx][1] == stones[i][1]){  // check all rown 1st index
                    dfs(n , i , visited , stones);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int group = 0;

        vector<bool>visited(n);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(n , i , visited , stones);
                group += 1;  // update 1 if condition is true
            }
        }
        return n-group;
    }
};
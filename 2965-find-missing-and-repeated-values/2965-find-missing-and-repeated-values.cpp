class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n*n;
        vector<int>freq(total+1 , 0);

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                freq[grid[i][j]]++;
            }
        }
        int a = -1, b = -1;
        for(int i=1; i<=total; i++){
            if(freq[i] == 2){
                a = i;
            }else if(freq[i] == 0){
                b=i;
            } 
        }
        return {a,b};
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int largest = arrays[0].back(); 
        int maxD = 0;
        for(int i=1; i<arrays.size(); ++i){
            maxD = max(maxD , abs(arrays[i].back() - smallest)); 
            maxD = max(maxD , abs(largest - arrays[i][0]));  
            smallest = min(smallest , arrays[i][0]);  
            largest = max(largest , arrays[i].back()); 
        }
        return maxD;
    }
};
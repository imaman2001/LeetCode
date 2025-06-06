class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort based on 2nd elements
        // use custom comparison operator
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        vector<int> prev = pairs[0];
        int ans = 1;

        for(int i=1; i<pairs.size(); i++){
            const vector<int>& curr = pairs[i];
            if(prev[1] < curr[0]){
                ans++;
                prev = curr;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort first all the intervals
        sort(intervals.begin() , intervals.end());

        // create a new 2D empty matrix
        vector<vector<int>> ans;
        int n = intervals.size();

        for(int i=0; i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(intervals[i][1] , ans.back()[1]);
            }
        }
        return ans;
    }
};
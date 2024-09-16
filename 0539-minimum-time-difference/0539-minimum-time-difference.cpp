class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);

        // covert time to minute
        for(int i=0; i<n; i++){
            int h = stoi(timePoints[i].substr(0,2));
            int m = stoi(timePoints[i].substr(3));
            minutes[i] = h * 60 + m;
        }

        //sort minutes
        sort(minutes.begin() , minutes.end());

        // Minumum Difference
        int diff = INT_MAX;
        for(int i=0; i< minutes.size() - 1; i++){
            diff = min(diff , minutes[i+1] - minutes[i]);
        }

        // difference between 24 hrs
        diff = min(diff , 24 * 60 - minutes.back() + minutes.front());

        return diff;
    }
};
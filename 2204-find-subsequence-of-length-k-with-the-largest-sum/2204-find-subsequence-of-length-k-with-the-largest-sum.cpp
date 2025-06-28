class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // pair<val, key>
        vector<pair<int, int>> latest;
        for(int i=0; i<nums.size(); i++){
            latest.push_back({nums[i] , i});
        }

        // sort in descending order based on value
        sort(latest.begin() , latest.end() , [](auto& a , auto& b){
            return a.first > b.first;
        });

        // index 0 to k
        vector<pair<int, int>> topele;
        for (int i = 0; i < k; i++) {
            topele.push_back(latest[i]);
        }
        sort(topele.begin(), topele.end() , [](auto& a , auto& b){
            return a.second < b.second;
        });

        vector<int> res;
        for(auto& ele : topele){
            res.push_back(ele.first);
        }

        return res;
    }
};
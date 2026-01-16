class Solution {
public:
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     set<vector<int>> ans;
    //     int n = nums.size();

    //     for(int i=0; i<n; i++){
    //         for(int j=i+1; j<n; j++){
    //             unordered_set<int> seen;
    //             for(int k=j+1; k<n; k++){
    //                 long long required = (long long)target - nums[i] - nums[j] - nums[k];

    //                 if(seen.count(required)){
    //                     vector<int> temp = {nums[i],nums[j],nums[k],(int)required};
    //                     sort(temp.begin(), temp.end());
    //                     ans.insert(temp);
    //                 }

    //                 seen.insert(nums[k]);
    //             }
    //         }
    //     }
    //     return vector<vector<int>>(ans.begin(), ans.end());
    // }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> st;
        
        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                int p1 = j+1;
                int p2 = n-1;

                while(p1 < p2){
                    long long sum = (long long)nums[i] + nums[j] + nums[p1] + nums[p2];

                    if(target == sum){
                        st.push_back({nums[i] , nums[j] , nums[p1] , nums[p2]});

                        while(p1 < p2 && nums[p1] == nums[p1 + 1]) {
                            p1++;
                        }

                        while(p1 < p2 && nums[p2] == nums[p2 - 1]){
                            p2--;
                        }

                        p1++;
                        p2--;
                    } else if(target > sum){
                        p1++;
                    } else {
                        p2--;
                    }   
                }
            }
        }
        return st;
    }
};
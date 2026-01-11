class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // vector<int>ans;
        // int n = nums.size();
        // vector<bool>isPossible(n+1 , false);

        // for(int i=0; i<n; i++){
        //     if(isPossible[nums[i]]){
        //         ans.push_back(nums[i]);
        //     }
        //     isPossible[nums[i]] = true;
        // }

        // for(int i=1; isPossible.size(); i++){
        //     if(isPossible[i] == false){
        //         ans.push_back(i);
        //         break;
        //     }

        // }
        // return ans;


    //......................... Another solution
        int n = nums.size();
        vector<int> hash(n+1 , 0);
        int missing = -1 , repeated = -1;

        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }

        for(int i=1; i<=n; i++){
            if(hash[i] == 2){
                repeated = i;
            } else if(hash[i] == 0){
                missing = i;
            }
        }

        // if(missing != -1 && repeated != -1){
        //     break;
        // }

        return {repeated , missing};
    }
};
class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n;

    //     vector<int> ans(n);
    //     for(int i=0; i<n; i++){
    //         ans[(i+k)%n] = nums[i];
    //     }
    //     for(int i=0; i<n; i++){
    //         nums[i] = ans[i];
    //     }
    // }

    void rotate(vector<int>& nums, int k){
        int n = nums.size();
        k = k % n;
        if(k != 0){
            vector<int>temp(nums.end()-k, nums.end()); // 5,6,7
            // temp = [5,6,7]
            temp.insert(temp.end(), nums.begin(), nums.end()-k); // temp = [5,6,7,1,2,3,4]
            copy(temp.begin(), temp.end(), nums.begin());
        }
    }
};
class Solution {
private:
    bool linearSearch(vector<int>& arr, int x){
        int next = x+1;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(next == arr[i]) return true;
        }
        return false;
    }
public:
    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 0) return 0;
    //     int longest = 1;

    //     for(int i=0; i<n; i++){
    //         int x = nums[i];
    //         int count = 1;

    //         while(linearSearch(nums, x) == true){
    //             x += 1;
    //             count += 1;
    //         }

    //         longest = max(longest , count);
    //     }
    //     return longest;
    // }

    // int longestConsecutive(vector<int>& nums) {
    //     int n = nums.size();

    //     if(n == 0) return 0;

    //     sort(nums.begin(), nums.end());

    //     int lastSmall = INT_MIN;
        

    //     int count = 0;
    //     int longest = 1;
    //     for(int i=0; i<n; i++){
    //         if(nums[i] - 1 == lastSmall){
    //             count =+ 1;
    //             lastSmall = nums[i];
    //         } else if(nums[i] != lastSmall){
    //             count = 1;
    //             lastSmall = nums[i];
    //         }
    //         longest = max(longest , count);
    //     }
    //     return longest;
    // }

// optimal solution
    int longestConsecutive(vector<int>& nums){
        if(nums.size() == 0) return 0;
        unordered_set<int>st;
        int longest = 1;
        for(int num : nums){
            st.insert(num);
        }

        //in set there are opposite meaning of (==) -> not found , (!=) -> found/match
        for(auto it : st){
            if(st.find(it - 1) == st.end()){    // if not found
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x + 1;
                    count += 1;
                }
                longest = max(longest , count);
            }
        }
        return longest;
    }
};
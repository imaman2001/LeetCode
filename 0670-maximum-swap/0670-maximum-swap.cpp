class Solution {
public:
    int maximumSwap(int num) {
        int maxIdx = -1 , swap1 = -1 , swap2 = -1;
        string nums = to_string(num);
        int n = nums.size();

        for(int i=n-1; i>=0; i--){
            if(maxIdx == -1 || nums[i] > nums[maxIdx]){
                maxIdx = i;
            } else if(nums[i] < nums[maxIdx]){
                swap1 = i;
                swap2 = maxIdx;
            }
        }

        if(swap1 != -1 && swap2 != -1){
            swap(nums[swap1] , nums[swap2]);
        }
        return stoi(nums);
    }
};
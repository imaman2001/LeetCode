class Solution {
public:
// BF
    // int trap(vector<int>& height){
    //     int n = height.size();
    //     vector<int>maxLeft(n);   // +1 size from height
    //     vector<int>maxRight(n);  // +1 size from height

    //     maxLeft[0] = height[0];
    //     maxRight[n-1] = height[n-1];

    //     //find the maxLeft
    //     for(int i=1; i<n; i++){
    //         maxLeft[i] = max(maxLeft[i-1] , height[i-1]);
    //     }

    //     //find the maxRight
    //     for(int i=n-2; i>=0; i--){
    //         maxRight[i] = max(maxRight[i+1], height[i+1]);
    //     }

    //     int sum = 0;
    //     for(int i=0; i<n; i++){
    //         int curr = min(maxLeft[i] , maxRight[i]) - height[i];

    //         if(curr > 0){
    //             sum = sum + curr;
    //         }
    //     }
    //     return sum;
    // }

    int trap(vector<int>& height){
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxLeft = 0;
        int maxRight = 0;
        int totalWater = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= maxLeft){
                    maxLeft = height[left];
                } else{
                    totalWater = totalWater + maxLeft - height[left];
                }
                left++;
            } else{
                if(height[right] >= maxRight){
                    maxRight = height[right];
                } else{
                    totalWater = totalWater + maxRight - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};
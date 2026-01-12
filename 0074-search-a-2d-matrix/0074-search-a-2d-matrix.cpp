class Solution {
public:
    bool binarySearch(vector<int>arr, int target){
        int st = 0; 
        int end = arr.size()-1;
        int mid = (st + end)/2;

        while(st <= end){
            if(target == arr[mid]){
                return true;
            } else if(target > arr[mid]){
                st = mid+1;
            } else{
                end = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();


        // for(int i=0; i<n; i++){
        //     if(matrix[i][0] <= target && target <= matrix[i][m-1]){
        //         return binarySearch(matrix[i], target);
        //     }
        // }
        // return false;

    //.......... optimal approach and with required TC: O(log(m * n)).....................
        int st = 0 , end = n*m-1;
        while(st <= end){
            // Calculate the middle index of the virtual 1D array
            int mid = (st + end)/2;

            // Convert mid index to corresponding 2D indices
            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col] == target){
                return true;
            } else if(matrix[row][col] < target){
                st = mid+1;
            } else {
                end = mid-1;
            }
        }
        return false;
    }
};
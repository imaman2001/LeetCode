class Solution {
    void merge(vector<int> &arr , int low , int mid , int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;

        while(left <= mid && right <= high){    // store elements in temp array in sorted manner
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){     //push left of the elements in left halves
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high){      //push left of the elements in right halves
            temp.push_back(arr[right]);
            right++;
        }

        int m=0;
        for(int i=low; i<=high; i++){
            arr[i] = temp[m++];     // check to do i on place i-1
        }
    }

    int countPair(vector<int> &arr, int low, int mid, int high){
        int cnt = 0;
        int right = mid+1;
        for(int i=low; i<=mid; i++){
            while(right <= high && arr[i] > 2*(long long)arr[right]){
                right++;
            } 
            cnt += (right - (mid+1));
        }
        return cnt;
    }
    
    int mergeSort(vector<int>& arr , int low , int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + high)/2;

        cnt += mergeSort(arr, low, mid);    // left half
        cnt += mergeSort(arr, mid+1, high); // right half
        cnt += countPair(arr, low, mid, high); // modification
        merge(arr, low, mid, high); // merge the rest of the halves
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};
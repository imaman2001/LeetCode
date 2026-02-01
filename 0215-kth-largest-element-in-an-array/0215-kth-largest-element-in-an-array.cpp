class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // it stores the small element on top of the tree
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = nums.size();

        for(int i=0; i<n; i++){
            pq.push(nums[i]);

            if(pq.size() > k){
                pq.pop();   //it removes the top element 
            }
        }
        return pq.top();
    }
};
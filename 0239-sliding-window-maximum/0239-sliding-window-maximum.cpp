class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // priority_queue<pair<int , int>>pq;
        // vector<int> ans;
        // for(int i=0; i<k; i++){
        //     pq.push(make_pair(nums[i], i));
        // }
        // ans.push_back(pq.top().first);

        // for(int i=k; i<nums.size(); i++){
        //     while(!pq.empty() && pq.top().second <= (i-k)){
        //         pq.pop();
        //     }
        //     pq.push(make_pair(nums[i], i));
        //     ans.push_back(pq.top().first);
        // }
        // return ans;

// using dequee
        deque<int>dq;
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
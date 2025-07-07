class Solution {
public:

    int maxEvents(vector<vector<int>>& events) {
        // sort the events based on first index
        sort(events.begin() , events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = events.size();
        int i=0 , day=0 , ans = 0;

        //while minHeap is not empty
        while(!minHeap.empty() || i < n){
            // if minHeap. is empty --> update day with events first index
            if(minHeap.empty()){
                day = events[i][0];
            }

            while(i < n && events[i][0] <= day){  // i=1 , 3<=3
                minHeap.push(events[i][1]);              // 4
                i++;
            }

            minHeap.pop();
            ans++;
            day++;

            // while minHeap is not empty and minHeap.top element is less than updated day
            while(!minHeap.empty() && minHeap.top() < day){
                minHeap.pop();
            }
        }
        return ans;
    }
};
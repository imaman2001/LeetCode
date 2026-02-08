class MedianFinder {
private:
    // vector<int>ans;
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:
    MedianFinder() { 
    }
    
    void addNum(int num) {
        // ans.push_back(num);
        maxHeap.push(num);

        // to balance both
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        //compare by size
        if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        // sort(ans.begin() , ans.end());
        // int n = ans.size();
        // if(n%2 == 1) return ans[n/2];
        // return (ans[n/2-1] + ans[n/2]) / 2.0;

        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int>PSE(n) ;
        vector<int>NSE(n);
        int maxArea = 0;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int>(); // empty for NSE

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i=0; i<n; i++){
            maxArea = max(maxArea, arr[i] * (NSE[i]-PSE[i]-1));
        }
        return maxArea;
    }
};
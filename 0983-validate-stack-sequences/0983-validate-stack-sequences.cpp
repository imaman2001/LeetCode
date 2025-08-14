class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n1 = pushed.size();
        int n2 = popped.size();
        bool flag = false;
        int j=0;
        stack<int> st;

        if(n1 != n2){
            return flag;
        }

        for(int i=0; i<n1; i++){
            while(!st.empty() && popped[j] == st.top()){
                st.pop();
                j++;
            }
            st.push(pushed[i]);
        }

        while(!st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }

        if(j >= n2){
            return true;
        }
        return flag;
    }
};
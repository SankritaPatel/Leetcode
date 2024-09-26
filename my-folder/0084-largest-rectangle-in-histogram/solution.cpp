class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();
        heights.push_back(0);
        for(int i=0;i<=n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int t = st.top();
                int h = heights[t];
                st.pop();
                int len;
                if(st.empty()){
                    len = i;
                }else{
                    len = i-st.top()-1;
                }
                ans = max(ans, h*len);
            }
            st.push(i);
        }

        return ans;
    }
};

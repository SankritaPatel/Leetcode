class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int n = height.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.top()]<height[i]){
                int curr = st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                // Calculate the distance to the left boundary
                int distnace = i-st.top()-1;
                // Calculate the bounded height
                int bounded_height = min(height[st.top()], height[i]) - height[curr];
                ans += distnace * bounded_height;
            }
            st.push(i);
        }
        return ans;
    }
};

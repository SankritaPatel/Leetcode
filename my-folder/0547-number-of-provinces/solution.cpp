class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjLS, vector<int>& vis) {
        vis[node] = 1; // Mark the current node as visited
        for (auto it : adjLS[node]) { // Traverse all adjacent nodes
            if (!vis[it]) {
                dfs(it, adjLS, vis); // Recursively visit unvisited nodes
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        // Initialize adjacency list
        vector<vector<int>> adjLS(V);
        
        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLS[i].push_back(j); // Add edge from i to j
                }
            }
        }
        
        int cnt = 0; // Count of connected components
        vector<int> vis(V, 0); // Initialize visited array with 0
        
        // Perform DFS to count connected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++; // Found a new component
                dfs(i, adjLS, vis); // Explore the component
            }
        }
        return cnt; // Return the count of connected components
    }
};


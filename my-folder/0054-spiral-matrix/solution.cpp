class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans; // Handle empty matrix case

        int n = matrix.size();
        int m = matrix[0].size();
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = n - 1;
        int colEnd = m - 1;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Traverse from left to right
            for (int j = colStart; j <= colEnd; j++) {
                ans.push_back(matrix[rowStart][j]);
            }
            rowStart++;

            // Traverse from top to bottom
            for (int i = rowStart; i <= rowEnd; i++) {
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            if (rowStart <= rowEnd) {
                // Traverse from right to left
                for (int j = colEnd; j >= colStart; j--) {
                    ans.push_back(matrix[rowEnd][j]);
                }
                rowEnd--;
            }

            if (colStart <= colEnd) {
                // Traverse from bottom to top
                for (int i = rowEnd; i >= rowStart; i--) {
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }

        return ans;
    }
};


class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) {
        part_sum.resize(matrix.size() + 1);
        for (unsigned int i = 0; i < part_sum.size(); i++) {
            part_sum[i].resize(matrix[0].size() + 1);
        }

        for (unsigned int i = 0; i < matrix.size(); i++) {
            int row_sum = 0;
            for (unsigned int j = 0; j < matrix[0].size(); j++) {
                row_sum += matrix[i][j];
                part_sum[i + 1][j + 1] = part_sum[i][j + 1] + row_sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return part_sum[row2 + 1][col2 + 1] - part_sum[row2 + 1][col1] - part_sum[row1][col2 + 1] + part_sum[row1][col1];
    }

   private:
    vector<vector<int>> part_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
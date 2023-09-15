double determinant(vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    }
    double det = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k < i) {
                    submatrix[j - 1][k] = matrix[j][k];
                } else if (k > i) {
                    submatrix[j - 1][k - 1] = matrix[j][k];
                }
            }
        }
        double submatrix_det = determinant(submatrix);// 遞迴計算行列式
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * submatrix_det;// 累積行列式值
    }
    return det;
}
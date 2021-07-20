impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut i = 0 * n + 0;
        let mut j = (m - 1) * n + (n - 1);
        let mut idx;
        let mut value;
        while i + 1 < j {
            idx = i + (j - i) / 2;
            value = matrix[idx / n][idx % n];
            if value < target {
                i = idx; 
            } else if value > target {
                j = idx;
            } else {
                return true;      
            }
        }
        
        return matrix[i / n][i % n] == target || matrix[j / n][j % n] == target;
    }
}

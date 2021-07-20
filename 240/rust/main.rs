impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let mut i = 0;
        let mut j = matrix[0].len() - 1;
        let mut value;
        while i < matrix.len() && j >= 0 {
            value = matrix[i][j];
            if value > target {
                if j == 0 {
                    break;
                }
                j -= 1;
            } else if value < target {
                i += 1;
            } else {
                return true;
            }
        }
        return false;
    }
}

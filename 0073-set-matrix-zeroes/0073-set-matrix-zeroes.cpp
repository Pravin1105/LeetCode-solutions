class Solution {
public:
    void zeroes(vector<vector<int>>& m, unordered_set<int> rows, unordered_set<int>cols){
        int n = m.size(), l = m[0].size();
        for(auto& it: rows){
            for(int i = 0; i<l; i++){
                m[it][i] = 0;
            }
        }
        for(auto& it: cols){
            for(int i = 0; i<n; i++){
                m[i][it] = 0;
            }
        }
        
        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<int> rows, cols;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        zeroes(matrix, rows, cols);
        return;
    }
};
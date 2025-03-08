class Solution {
public:

//1. calculate the transpose of the given matrix.
//2. reverse the first and last element of the each row. so, it become rotate image
//TC : O(n^2)
//SC : O(1) in-place rotation
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};
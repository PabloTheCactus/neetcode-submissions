class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = matrix.size() - 1;
        int bottom = 0;
        int row = 0;
        if(matrix[0].size() == matrix.size() && matrix.size() == 1){
            if(matrix[0][0] == target){return true;}
            else return false;
        }
        while(bottom<=top){
            row = bottom + (top - bottom) / 2;
            if(matrix[row][matrix[0].size() - 1] < target){bottom = row + 1;}// matrix[0].size() - 1 і 0 це сталі вони ж не змінні
            else if(matrix[row][0] > target){top = row - 1;}
            else break;
        }
        if (!(bottom <= top)) {// ця умова безпалєзна
            return false;
        }
        int topcol = matrix[0].size() - 1;
        int lowcol = 0;
        int middle = 0;
        while(lowcol <= topcol){
            middle = lowcol + (topcol - lowcol) / 2;
            if(matrix[row][middle] < target){lowcol = middle + 1;}
            else if(matrix[row][middle] > target){topcol = middle - 1;}
            else return true;
        }
        return false;
    }
};
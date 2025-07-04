/*Question: You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Solution:
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total_size = rows * cols;
        int start = 0;
        int end = total_size - 1;
        while(start <= end) {
            int mid = (start + end)/2;
            int row_index = mid / cols;
            int col_index = mid % cols;
            int element = matrix[row_index][col_index];
            if(element == target) return true;
            else if(element < target) start = mid + 1;
            else end = mid - 1; 
        }
        return false;
    }
};
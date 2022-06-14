class Solution
{
public:
    bool search(vector<vector<int>> &matrix, int m, int n, int target)
    {
        for (int i = 0; i < n; i++)
        {
            if (matrix[m][i] == target)
                return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // 3
        int n = matrix[0].size(); // 4

        for (int i = 0; i < m; i++)
        {

            if (matrix[i][n - 1] == target)
                return true;

            if (matrix[i][n - 1] > target)
                return search(matrix, i, n, target);
        }
        return false;
    }
};
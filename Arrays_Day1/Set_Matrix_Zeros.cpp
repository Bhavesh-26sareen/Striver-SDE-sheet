class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // vector<int> rows(m ,-1);
        // vector<int> cols(n,-1) ;
        // Space O(m+n)
        // Further optimize ?
        // Can we Reduce our Space complexity to O(1)
        //
        // Time O(m*n)
        /* for(int i = 0; i< m ; i++)
         {
             for(int j = 0 ; j< n ; j++)
             {
                 if(matrix[i][j] == 0)
                 {
                     rows[i] = 0 ;
                     cols[j] = 0 ;
                 }
             }
         }
         for(int i = 0 ; i< m ; i++)
         {
             for(int j = 0 ; j < n ; j++)
             {
                 if (rows[i] == 0 || cols[j] == 0)
                 {
                     matrix[i][j] = 0 ;

                 }
             }
         }*/
        bool row = false;
        bool col = false;

        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == 0)
                row = true;
        }
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                col = true;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        // cout<<col << row<<endl;
        if (row)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
        if (col)
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
    }
};
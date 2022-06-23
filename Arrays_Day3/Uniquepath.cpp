class Solution
{
public:
    /* int getCount(int i, int j , int m, int n , vector<vector<int>>&dp)
     {
         if(i>=m || j>=n) return 0 ;
         if(i == m-1 && j == n-1) return 1 ;

         if(dp[i][j] != -1) return dp[i][j] ;

         return dp[i][j] = getCount(i+1 , j , m , n , dp) + getCount(i ,j+1 , m , n , dp) ;
     }*/

    int uniquePaths(int m, int n)
    {
        /*vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1)) ;
        return getCount(0 , 0 , m , n , dp) ;*/
        int N = m + n - 2;
        int R = min(n, m) - 1;

        int ans = 1;
        for (int i = 1; i <= R; i++)
        {
            ans = ans * 1LL * (N - R + i) / i;
        }
        return (int)ans;
    }
};
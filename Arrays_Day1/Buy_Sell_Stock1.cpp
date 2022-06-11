class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        /*
            0 1 2 3 4 5
            7 1 5 3 6 4

            buy = 1 , 5 ,3 , 6
            sell =6 , 6 , 6
            profit = 5 , 1 , 3
        */

        // O(n^2)
        // n*n = 10^5 * 10 ^5 = 10 ^ 10 operations
        // This might not work
        // It will give TLE

        int buy = INT_MAX;
        int sell = INT_MIN;
        int profit = 0;
        for (auto price : prices)
        {
            if (buy > price)
            {
                buy = price;
                sell = price;
            }
            else if (sell < price)
            {
                sell = price;
                profit = max(profit, sell - buy);
            }
        }
        return profit;
        // O(n)
    }
};
class Solution
{
public:
    double myPow(double x, int n)
    {
        bool flag = false;
        long nn;
        if (n < 0)
        {
            flag = true;
            nn = labs(n);
            // cout<<n<<endl;
        }
        // cout<<n<<endl;
        double ans = 1.0;
        while (nn)
        {
            if (nn % 2 == 1)
            {
                ans *= x;
                nn -= 1;
            }
            else
            {
                x = x * x;
                nn /= 2;
            }
        }
        if (flag)
            ans = 1 * 1.0 / ans;
        return ans;
    }
};
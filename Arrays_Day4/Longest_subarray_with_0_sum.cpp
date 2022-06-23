class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        /*1)
        sorting (nlogn)

        */
        /*2)
          using some data structure to store the element and then finding the starting element of the longest               consecutive seq
        */

        unordered_set<int> st(begin(nums), end(nums));

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.count(nums[i] - 1) == 0)
            {
                int temp = 1;

                while (st.count(nums[i] + temp) == 1)
                {
                    temp++;
                }
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};
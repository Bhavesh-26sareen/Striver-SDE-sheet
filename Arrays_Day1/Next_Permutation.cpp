class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // 1 2 3
        int n = nums.size();
        int idx = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                // swap(nums[i] , nums[i+1]) ;
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int x = nums[idx];
        int xx = nums[idx + 1];
        int id = idx + 1;
        for (int i = idx + 1; i < n; i++)
        {
            if (x < nums[i])
            {
                // xx = min(xx , nums[i]) ;
                if (xx > nums[i])
                {
                    id = i;
                    xx = nums[i];
                }
            }
        }
        swap(nums[idx], nums[id]);
        sort(nums.begin() + idx + 1, nums.end());
    }
};
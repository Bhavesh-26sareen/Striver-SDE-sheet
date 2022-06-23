int Solution::solve(vector<int> &nums, int B)
{
    int n = nums.size();
    map<int, int> freq;
    int xor_ = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        xor_ ^= nums[i];
        if (xor_ == B)
            ans++;

        int y = xor_ ^ B;
        if (freq.count(y))
        {
            ans += freq[y];
        }
        freq[xor_]++;
    }
    return ans;
}

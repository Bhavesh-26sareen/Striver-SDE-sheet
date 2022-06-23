class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            int a = nums[i];
            for (int j = i + 1; j < n - 2; j++)
            {
                int s = j + 1, e = n - 1;
                while (s < e)
                {
                    long long int temp = a + nums[j];
                    temp += nums[s] + nums[e];
                    if (temp < target)
                        s++;
                    else if (temp > target)
                        e--;
                    else
                    {
                        vector<int> line;
                        line.push_back(a);
                        line.push_back(nums[j]);
                        line.push_back(nums[s]);
                        line.push_back(nums[e]);
                        ans.push_back({a, nums[j], nums[s], nums[e]});
                        s++;
                        e--;
                        // -2 -1 -1 1 1 2 2
                        while (s < e && nums[s - 1] == nums[s])
                            s++;
                    }
                }
                while (j < n - 2 && nums[j + 1] == nums[j])
                    j++;
            }
            while (i < n - 3 && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};
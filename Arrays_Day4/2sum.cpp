class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> omap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            omap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if (omap.find(x) != omap.end())
            {
                if (omap[x] == i)
                    continue;
                result.push_back(i);
                result.push_back(omap[x]);
                break;
            }
        }
        return result;
    }
};
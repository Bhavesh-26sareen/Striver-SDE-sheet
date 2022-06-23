class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> freq(256, -1);
        int left = 0;
        int right = 0;
        int ans = 0;

        int n = s.length();
        while (right < n)
        {
            if (freq[s[right]] != -1)
            {
                left = max(freq[s[right]] + 1, left);
            }

            freq[s[right]] = right;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

// ____
// abcabcbb
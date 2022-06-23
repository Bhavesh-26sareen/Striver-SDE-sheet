class Solution
{
public:
    int cnt = 0;
    void merge(int start, int mid, int end, vector<int> &nums)
    {
        vector<int> output(end - start + 1);
        int j = mid + 1;
        for (int i = start; i <= mid; i++)
        {
            while (j <= end && nums[i] > 2 * 1LL * nums[j])
                j++;
            cnt += (j - (mid + 1));
        }
        int i = start;
        j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end)
        {
            if (nums[i] <= nums[j])
            {
                output[k++] = nums[i];
                i++;
            }
            else if (nums[i] > nums[j])
            {
                // cout<<nums[i]<<" "<<nums[j] <<endl;
                // if(nums[i] == 2*nums[j])
                // {
                //     cnt += mid-i;
                //     // cout<<"hii"<<endl;
                // }
                // else if(nums[i] > 2*nums[j])
                // {
                //     cnt+= mid-i+1 ;
                //     // cout<<"hello " << mid <<" " << i <<endl;
                // }
                output[k++] = nums[j];
                j++;
            }
        }
        while (i <= mid)
        {
            output[k++] = nums[i++];
        }
        while (j <= end)
            output[k++] = nums[j++];

        for (int i = start; i <= end; i++)
        {
            nums[i] = output[i - start];
        }
    }
    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start < end)
        {
            int mid = (start) + (end - start) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(start, mid, end, nums);
        }
    }
    int reversePairs(vector<int> &nums)
    {
        // 1 2 3 4 5
        //  2 4 3 5 1
        // 4 8 6 10 2
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return cnt;
    }
};
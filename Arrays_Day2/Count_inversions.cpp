#include <bits/stdc++.h>

long long cnt = 0;
void merge(long long *arr, int si, int mid, int ei)
{
    long long output[ei - si + 1];
    int i = si;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            output[k++] = arr[i];
            i++;
        }
        else
        {
            output[k++] = arr[j];
            cnt += (mid - i + 1);
            j++;
        }
    }
    while (i <= mid)
    {
        output[k++] = arr[i++];
    }
    while (j <= ei)
    {
        output[k++] = arr[j++];
    }
    for (int i = si; i <= ei; i++)
        arr[i] = output[i - si];
}
void mergesort(long long *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start) + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    mergesort(arr, 0, n - 1);
    return cnt;
}
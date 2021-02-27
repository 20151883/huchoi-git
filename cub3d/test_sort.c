#include <stdio.h>

void ft_merge(double *arr, int start, int mid, int end)
{
    double temp[end - start + 1];
    int idx = 0;
    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (arr[left] < arr[right])
            temp[idx] = arr[left++];
        else
            temp[idx] = arr[right++];
        idx++;
    }
    if (left <= mid)
    {
        while (left <= mid)
            temp[idx++] = arr[left++];
    }
    else if (right <= end)
    {
        while (right <= end)
            temp[idx++] = arr[right++];
    }
    idx= start;
    while (idx <= end)
    {
        arr[idx] = temp[idx - start];
        idx++;
    }
}

void ft_mergesort(double *arr, int start, int end)
{
    int mid;

    if (start == end)
        return;
    mid = (start + end) / 2;
    ft_mergesort(arr, start, mid);
    ft_mergesort(arr, mid+1, end);
    ft_merge(arr, start, mid, end);
}

int main(void)
{
    double arr[10] = {9,2,0,1,5,6,7,8,4,3};
    ft_mergesort(arr, 0, 9);
    int i = 0;
    while (i < 10)
        printf("%l", arr[i]);
}
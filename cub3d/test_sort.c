double compute_dis(t_syn *p_syn, double *sprite)
{
    double ret;
    double x_pos;
    double y_pos;

    ret = (x_pos - p_syn->tri.pos[0]) * (x_pos - p_syn->tri.pos[0]);
    ret +=  (y_pos - p_syn->tri.pos[1]) * (y_pos - p_syn->tri.pos[1]);
    ret = sqrt(ret);
    return (ret);
}

void ft_merge(double **arr, int start, int mid, int end)
{
    double *temp[end - start + 1];
    int idx = 0;
    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (compute_dis(arr[left]) < compute_dis(arr[right]))
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

void ft_mergesort(double **arr, int start, int end)
{
    int mid;

    if (start == end)
        return;
    mid = (start + end) / 2;
    ft_mergesort(arr, start, mid);
    ft_mergesort(arr, mid+1, end);
    ft_merge(arr, start, mid, end);
}//git petch...?

int main(void)
{
    double arr[5][2] = {9,4,0,5,1,7,6,3,2,8};
    double **ptr = arr;
}
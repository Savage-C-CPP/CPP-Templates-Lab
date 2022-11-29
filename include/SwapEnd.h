template <typename T>
T *SwapEnd(T arr[], int len)
{
    if (len < 4)
        return arr;

    T *swapped = new T[len];

    int start_index;
    if (len % 2 == 0)
        start_index = len / 2;
    else
        start_index = 1 + (len - 1) / 2;

    size_t i = 0, j = len - 1;
    while (i < len)
    {
        while (i < start_index)
            swapped[i++] = arr[i];
        swapped[i++] = arr[j--];
    }

    return swapped;
}
#include <iostream>

void quickSort(int *nums, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = nums[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (nums[i] < pivot)
            i++;
        while (nums[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(nums, low, j);
    if (i < high)
        quickSort(nums, i, high);
}
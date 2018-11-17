#include <iostream>

using namespace std;

void merge(int *A, int, int, int);
void mergeSort(int *A, int p, int r);

void merge(int *arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];
    int i = 0;
    int j = 0;
    int n = 0;
    while (i != n1 && j != n2)
    {
        if (L[i] > R[j])
        {
            arr[p + n] = R[j];
            j++;
        }
        else
        {
            arr[p + n] = L[i];
            i++;
        }
        n++;
    }
    while (j != n2)
    {
        arr[p + n] = R[j];
        j++;
        n++;
    }
    while (i != n1)
    {
        arr[p + n] = L[i];
        i++;
        n++;
    }
}
void mergeSort(int *arr, int p, int r)
{
    if (r > p)
    {
        int q;
        q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
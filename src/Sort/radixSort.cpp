#include <algorithm>
#include <iostream>
#include <iterator>

class radixSort
{
    const int bit;

  public:
    radixSort(int offset) : bit(offset) {}

    bool operator()(int value) const
    {
        if (bit == 31)
            return value < 0;
        else
            return !(value & (1 << bit));
    }
};

void radixSortLeastSignificantDigit(int *first, int *last)
{
    for (int lsb = 0; lsb < 32; ++lsb)
    {
        std::stable_partition(first, last, radixSort(lsb));
    }
}

void radixSortMostSignificantDigit(int *first, int *last, int msb = 31)
{
    if (first != last && msb >= 0)
    {
        int *mid = std::partition(first, last, radixSort(msb));

        msb--;
        radixSortMostSignificantDigit(first, mid, msb);
        radixSortMostSignificantDigit(mid, last, msb);
    }
}
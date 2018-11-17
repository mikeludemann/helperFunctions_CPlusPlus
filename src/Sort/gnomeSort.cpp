#include <algorithm>
#include <iterator>
#include <iostream>

template <typename RandomAccessIterator>
void gnomeSort(RandomAccessIterator begin, RandomAccessIterator end)
{
    auto i = begin + 1;
    auto j = begin + 2;

    while (i < end)
    {
        if (!(*i < *(i - 1)))
        {
            i = j;
            ++j;
        }
        else
        {
            std::iter_swap(i - 1, i);
            --i;
            if (i == begin)
            {
                i = j;
                ++j;
            }
        }
    }
}
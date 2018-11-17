#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

template <typename ForwardIterator>
void countingSort(ForwardIterator begin, ForwardIterator end)
{
    auto min_max = std::minmax_element(begin, end);

    if (min_max.first == min_max.second)
    {
        return;
    }

    auto min = *min_max.first;
    auto max = *min_max.second;

    std::vector<unsigned> count((max - min) + 1, 0u);

    for (auto i = begin; i != end; ++i)
    {
        ++count[*i - min];
    }

    for (auto i = min; i <= max; ++i)
    {
        for (auto j = 0; j < count[i - min]; ++j)
        {
            *begin++ = i;
        }
    }
}